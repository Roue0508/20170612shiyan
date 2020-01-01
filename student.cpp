#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define M 50
void menu();
void input();
insert(int n);
void correctrec();
void deleterec();
void inputmark();
void change();
void scanmark();
void write_new();
space(int n);
int N=10;
struct student
{
    int number;
    char name[20];
    int age;
    int score[3];
}stu[M];
 //输出空格函数
space(int n)       
{
    int i;
    for(i=0;i<n;i++)
    printf(" ");
    return 0;
}
//将修改后的信息写入文件
void write_new()
{			
	FILE *fp;
    int i;    
    if((fp=fopen("records of students.txt","w"))==NULL)
	{
		printf("open file error!\n");
		exit(0);
	}
	for(i=0;i<N;i++)
	{
		fprintf(fp,"%d %s %d %d %d %d",stu[i].number,stu[i].name,stu[i].age,
		                 stu[i].score[0],stu[i].score[1],stu[i].score[2]);
		fprintf(fp,"\n");
	} 
	fclose(fp);
       
}
//输入记录
void input()
{ 
	int i;
	FILE *fp;
	if((fp=fopen("records of students.txt","r"))==NULL)
	{
		printf("open file error\n");
		exit(0);
	}
	for(i=0;i<N;i++)
		fscanf(fp,"%d %s %d %d %d %d",&stu[i].number,stu[i].name,&stu[i].age,
		&stu[i].score[0],&stu[i].score[1],&stu[i].score[2]);            //从指定文件读入学生记录
	fclose(fp);
        
}
//插入n个学生的记录
insert(int n)
{
    //FILE *fp;    
    int i,j;
    i=N;
    for(j=0;j<n;j++)
	{
		printf("输入第%d个要插入学生的信息:\n",j+1);
        printf("the information is number(五位整数),name,age,math,english,physics in order\n");
		scanf("%d%s%d%d%d%d",&stu[i].number,stu[i].name,&stu[i].age,&stu[i].score[0],&stu[i].score[1],&stu[i].score[2]);
        N=N+1;                 //加入一个数据后学生总数加一
	}          
    /*if((fp=fopen("records of students.txt","a"))==NULL)
    {
		printf("open file error\n");
		exit(0);
    }*/
    
    write_new();      //将插入学生后的信息写入文件
	printf("the information in the file now is:\n");
	scanmark();        //浏览插入学生后的文件信息
	return 0;
}
//修改某n个学生的记录
void correctrec()
{
	int q;
	int i,k;
	printf("输入待修改记录学生的学号(五位):\n");
	scanf("%d",&q);
A0:	for(i=0;i<N;i++)
		if(q==stu[i].number)	
		{
			k=i;
			printf("the student's original information is :\n");
			break;
		}
		if(i==N)                        //输入错误提示
		{
			printf("刚才的学号不存在，再输：");
			scanf("%d",&q);
			goto A0;
		}
	printf("number	name    age	  mathscore	  engscore	 physcore\n");//输出格式控制及输出
	printf("%d	%s	%d",stu[k].number,stu[k].name,stu[k].age);
	for(i=0;i<3;i++)
		printf("   %d",stu[k].score[i]);
	printf("\n");
	printf("you can input the changed information now:\n");
	printf("number	name	age		math	english		physics\n");
	scanf("%d%s%d",&stu[k].number,stu[k].name,&stu[k].age);
	scanf("%d%d%d",&stu[k].score[0],&stu[k].score[1],&stu[k].score[2]);
	printf("the information after being corrected is :\n");\
	write_new();      //将修改学生信息后的记录写入文件并浏览
	printf("the information in the file now is:\n");
	scanmark();
		
}
//成绩录入函数
void inputmark()
{
	int i,k;
	int q;
	printf("please input number of the student to which you want to give marks:\n");
	scanf("%d",&q);
loop:	for(i=0;i<N;i++)
		if(stu[i].number==q)
		{
			k=i;
			printf("input marks to the student %s(%d)\n",stu[k].name,stu[k].number);
			printf("the marks are about math,english,physics in order\n");
			scanf("%d%d%d",&stu[k].score[0],&stu[k].score[1],&stu[k].score[2]);
			break;
		}
		if(i==N)            //出错提示
		{
		printf("the number you just input doesn't exist,input again!\n");
		scanf("%d",&q);
		goto loop;
		}
		write_new();      //将修改后的记录写入文件
	    printf("the information in the file now is:\n");
	    scanmark();
		
}


//成绩浏览函数
void scanmark()
{
    int i,j;
    struct student t;
    int sum[10];
    input();
	for(i=0;i<N;i++)
    sum[i]=stu[i].score[0]+stu[i].score[1]+stu[i].score[2];//计算每个学生的总成绩
    for(i=0;i<N;i++)
	{
		printf("第%d个学生的总成绩为:",i+1);
		printf("%d\n",sum[i]);
	}
	printf("the marks of the whole class in the order of the students' number\n");
    printf("are as follows:\n");
    /* 根据学号排序 */
    for(i=0;i<N-1;i++)
    for(j=i+1;j<N;j++)
	{
        if(stu[j].number<=stu[i].number)
        {
            t=stu[i];
            stu[i]=stu[j];
            stu[j]=t;
        }
    }
          //如下打印的格式控制及输出
        printf("number            name             age          math        english      physics\n");
    for(i=0;i<N;i++)
    {
        printf("%5d            %s            %2d",stu[i].number,stu[i].name,stu[i].age);
        for(j=0;j<3;j++)
        {
            space(10);
            printf("%3d",stu[i].score[j]);
        }
            printf("\n");

    }
}
//目录函数
void menu()
{
	  printf("\t\t*****************学生成绩管理系统*****************\n");
      printf("\t\t　　　　　　　　　　　　　　　　　　　　　        \n");
      printf("\t\t　　　　　　　    A.插入学生信息　　　　　　　    \n");
      printf("\t\t        　　　　　　　　　　　　　　　　　　　　　\n");
      printf("\t\t　　　　　　      B.修改学生信息　　　　　　　    \n");
      printf("\t\t　　　　　　　　　　　　　　　　　　　　　        \n");
      printf("\t\t        　　　    C.删除学生信息    　　　　　    \n");
      printf("\t\t　　　　　　　　　　　　　　　　　　　　　        \n");
      printf("\t\t    　　　　　　　D.登记成绩　　　　　            \n");
      printf("\t\t　　　　　　　　　　　　　　　　　　　　　        \n"); 
      printf("\t\t    　　　　　　　E.修改成绩　　　　　　　        \n");
      printf("\t\t                                                  \n");
      printf("\t\t    　　　　　　　F.浏览全班成绩　　　　　　　    \n");
      printf("\t\t                                                  \n");
      printf("\t\t    　            G.保存并退出系统　　　　　　    \n");
      printf("\t\t                                                  \n");
      printf("\t\t**************************************************\n");
}
//修改n个学生的成绩
void change()
{
	FILE *fp;
	int i,k,n;
	int p;
	if((fp=fopen("records of students.txt","r"))==NULL)
	{
		printf("open file error\n");
		exit(0);
	}
	for(i=0;i<N;i++)
		fscanf(fp,"%d%s%d%d%d%d",&stu[i].number,stu[i].name,&stu[i].age,
		&stu[i].score[0],&stu[i].score[1],&stu[i].score[2]);
	fclose(fp);
	printf("please input the number of the student whose mark you want to change:\n");
    scanf("%d",&p);
loop1:  for(i=0;i<N;i++)                //按学号寻找目标学生
			if(p==stu[i].number)
			{
			k=i;
			break;
			}
		
        if(i==N)                             //输入出错提示
		{
		printf("the number you just input doesn't exist,input again!\n");
        i=0;
		scanf("%d",&p);
		goto loop1;
		}
		printf("choose the course that you want change:\n");
        printf("1:math\n2:english\n3:physics\n");         //选择要修改课程的名称
        scanf("%d",&n);
loop2:	switch(n)
			{
				case 1: 
					{
						printf("input the marks that they should be please:\n");
					    scanf("%d",&stu[k].score[0]);break;
					}
                case 2:
					{
						printf("input the marks that they should be please:\n");
						scanf("%d",&stu[k].score[1]);break;
					}
				case 3:
					{
						printf("input the marks that they should be please:\n");
						scanf("%d",&stu[k].score[2]);break;
					}
				default:{                                            //输入出错提示
					printf("illigel operation!choose again!\n");
					scanf("%d",&n);
					goto loop2;                  
						}
			}
           //将修改后的成绩写入文件并浏览
			write_new();
			printf("n个学生的成绩被修改后的文件内容:\n");
			scanmark();
}
//删除某学生的信息
void deleterec()
{
	int q,p;
	int i,j,k;
	printf("输入拟修改成绩学生的学号:");
	scanf("%d",&q);
loop3:	for(i=0;i<N;i++)
		if(stu[i].number==q)
		{
			k=i;
			break;
		}
		if(i==N)              //输入错误提示
		{
			printf("刚才输入的学号不存在，再输:\n");
			scanf("%d",&q);
			goto loop3;
		}
	printf("你确定要删除职工%d(%s)的信息?\n",stu[k].number,stu[k].name); //确认删除操作
	printf("0.取消\n1.确定\n");
	scanf("%d",&p);
	switch(p)
	{
	case 1:
		{
			for(k;k<N;k++)            //删除所选学生记录
			{
				j=k+1;
		    stu[k]=stu[j];
			}
			N--;               //在学生总数中减一
            write_new();      //将修改后的记录写入文件
	        printf("the information in the file now is:\n");//打印修改后的文件内容
	        scanmark();
		break;
		}
	case 0: break;
	}
}
//主函数
void main()
{
	int n;
	char p;
	menu();//显示目录
	input();    //录入成绩
	while(1)
	{
		printf("请输入您要进行的操作(不分字母大小写):");
		scanf("%c",&p);
	    if(p<='z'&&p>='a')
			p=p-32;
		if((p=='G')|(p=='g'))
			break;                     //退出系统
        switch(p)                      //选择操作
		{
	      case 'A':
			  {
			printf("请输入要插入信息的学生数：\n");
			scanf("%d",&n);
			insert(n);
			system("pause");
			system("cls");
			break;
			  }
	      case 'B': correctrec();system("pause");system("cls");break;
	      case 'C': deleterec();system("pause");system("cls");break;
	      case 'D': inputmark();system("pause");system("cls");break;
	      case 'E': change();system("pause");system("cls");break;
	      case 'F': scanmark();system("pause");system("cls");break;
		 }
	      menu();
	}
}
