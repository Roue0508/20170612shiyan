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
 //����ո���
space(int n)       
{
    int i;
    for(i=0;i<n;i++)
    printf(" ");
    return 0;
}
//���޸ĺ����Ϣд���ļ�
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
//�����¼
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
		&stu[i].score[0],&stu[i].score[1],&stu[i].score[2]);            //��ָ���ļ�����ѧ����¼
	fclose(fp);
        
}
//����n��ѧ���ļ�¼
insert(int n)
{
    //FILE *fp;    
    int i,j;
    i=N;
    for(j=0;j<n;j++)
	{
		printf("�����%d��Ҫ����ѧ������Ϣ:\n",j+1);
        printf("the information is number(��λ����),name,age,math,english,physics in order\n");
		scanf("%d%s%d%d%d%d",&stu[i].number,stu[i].name,&stu[i].age,&stu[i].score[0],&stu[i].score[1],&stu[i].score[2]);
        N=N+1;                 //����һ�����ݺ�ѧ��������һ
	}          
    /*if((fp=fopen("records of students.txt","a"))==NULL)
    {
		printf("open file error\n");
		exit(0);
    }*/
    
    write_new();      //������ѧ�������Ϣд���ļ�
	printf("the information in the file now is:\n");
	scanmark();        //�������ѧ������ļ���Ϣ
	return 0;
}
//�޸�ĳn��ѧ���ļ�¼
void correctrec()
{
	int q;
	int i,k;
	printf("������޸ļ�¼ѧ����ѧ��(��λ):\n");
	scanf("%d",&q);
A0:	for(i=0;i<N;i++)
		if(q==stu[i].number)	
		{
			k=i;
			printf("the student's original information is :\n");
			break;
		}
		if(i==N)                        //���������ʾ
		{
			printf("�ղŵ�ѧ�Ų����ڣ����䣺");
			scanf("%d",&q);
			goto A0;
		}
	printf("number	name    age	  mathscore	  engscore	 physcore\n");//�����ʽ���Ƽ����
	printf("%d	%s	%d",stu[k].number,stu[k].name,stu[k].age);
	for(i=0;i<3;i++)
		printf("   %d",stu[k].score[i]);
	printf("\n");
	printf("you can input the changed information now:\n");
	printf("number	name	age		math	english		physics\n");
	scanf("%d%s%d",&stu[k].number,stu[k].name,&stu[k].age);
	scanf("%d%d%d",&stu[k].score[0],&stu[k].score[1],&stu[k].score[2]);
	printf("the information after being corrected is :\n");\
	write_new();      //���޸�ѧ����Ϣ��ļ�¼д���ļ������
	printf("the information in the file now is:\n");
	scanmark();
		
}
//�ɼ�¼�뺯��
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
		if(i==N)            //������ʾ
		{
		printf("the number you just input doesn't exist,input again!\n");
		scanf("%d",&q);
		goto loop;
		}
		write_new();      //���޸ĺ�ļ�¼д���ļ�
	    printf("the information in the file now is:\n");
	    scanmark();
		
}


//�ɼ��������
void scanmark()
{
    int i,j;
    struct student t;
    int sum[10];
    input();
	for(i=0;i<N;i++)
    sum[i]=stu[i].score[0]+stu[i].score[1]+stu[i].score[2];//����ÿ��ѧ�����ܳɼ�
    for(i=0;i<N;i++)
	{
		printf("��%d��ѧ�����ܳɼ�Ϊ:",i+1);
		printf("%d\n",sum[i]);
	}
	printf("the marks of the whole class in the order of the students' number\n");
    printf("are as follows:\n");
    /* ����ѧ������ */
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
          //���´�ӡ�ĸ�ʽ���Ƽ����
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
//Ŀ¼����
void menu()
{
	  printf("\t\t*****************ѧ���ɼ�����ϵͳ*****************\n");
      printf("\t\t������������������������������������������        \n");
      printf("\t\t��������������    A.����ѧ����Ϣ��������������    \n");
      printf("\t\t        ������������������������������������������\n");
      printf("\t\t������������      B.�޸�ѧ����Ϣ��������������    \n");
      printf("\t\t������������������������������������������        \n");
      printf("\t\t        ������    C.ɾ��ѧ����Ϣ    ����������    \n");
      printf("\t\t������������������������������������������        \n");
      printf("\t\t    ��������������D.�Ǽǳɼ�����������            \n");
      printf("\t\t������������������������������������������        \n"); 
      printf("\t\t    ��������������E.�޸ĳɼ���������������        \n");
      printf("\t\t                                                  \n");
      printf("\t\t    ��������������F.���ȫ��ɼ���������������    \n");
      printf("\t\t                                                  \n");
      printf("\t\t    ��            G.���沢�˳�ϵͳ������������    \n");
      printf("\t\t                                                  \n");
      printf("\t\t**************************************************\n");
}
//�޸�n��ѧ���ĳɼ�
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
loop1:  for(i=0;i<N;i++)                //��ѧ��Ѱ��Ŀ��ѧ��
			if(p==stu[i].number)
			{
			k=i;
			break;
			}
		
        if(i==N)                             //���������ʾ
		{
		printf("the number you just input doesn't exist,input again!\n");
        i=0;
		scanf("%d",&p);
		goto loop1;
		}
		printf("choose the course that you want change:\n");
        printf("1:math\n2:english\n3:physics\n");         //ѡ��Ҫ�޸Ŀγ̵�����
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
				default:{                                            //���������ʾ
					printf("illigel operation!choose again!\n");
					scanf("%d",&n);
					goto loop2;                  
						}
			}
           //���޸ĺ�ĳɼ�д���ļ������
			write_new();
			printf("n��ѧ���ĳɼ����޸ĺ���ļ�����:\n");
			scanmark();
}
//ɾ��ĳѧ������Ϣ
void deleterec()
{
	int q,p;
	int i,j,k;
	printf("�������޸ĳɼ�ѧ����ѧ��:");
	scanf("%d",&q);
loop3:	for(i=0;i<N;i++)
		if(stu[i].number==q)
		{
			k=i;
			break;
		}
		if(i==N)              //���������ʾ
		{
			printf("�ղ������ѧ�Ų����ڣ�����:\n");
			scanf("%d",&q);
			goto loop3;
		}
	printf("��ȷ��Ҫɾ��ְ��%d(%s)����Ϣ?\n",stu[k].number,stu[k].name); //ȷ��ɾ������
	printf("0.ȡ��\n1.ȷ��\n");
	scanf("%d",&p);
	switch(p)
	{
	case 1:
		{
			for(k;k<N;k++)            //ɾ����ѡѧ����¼
			{
				j=k+1;
		    stu[k]=stu[j];
			}
			N--;               //��ѧ�������м�һ
            write_new();      //���޸ĺ�ļ�¼д���ļ�
	        printf("the information in the file now is:\n");//��ӡ�޸ĺ���ļ�����
	        scanmark();
		break;
		}
	case 0: break;
	}
}
//������
void main()
{
	int n;
	char p;
	menu();//��ʾĿ¼
	input();    //¼��ɼ�
	while(1)
	{
		printf("��������Ҫ���еĲ���(������ĸ��Сд):");
		scanf("%c",&p);
	    if(p<='z'&&p>='a')
			p=p-32;
		if((p=='G')|(p=='g'))
			break;                     //�˳�ϵͳ
        switch(p)                      //ѡ�����
		{
	      case 'A':
			  {
			printf("������Ҫ������Ϣ��ѧ������\n");
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
