#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h> 
typedef struct people{
	char name[15];			//���� 
	char card_id[10];		//�˺�id
	char peo_id[20];		//���֤id
	char phone_num[10];		//�ֻ�����
	float account;			//�˻����	   
}peo;
//typedef struct time{
//	int year[10];	
//	int month[10];
//	int day[10];
//	int hour[10];
//	int minutes[10];
//	int second[10];
//	char behavior[10];
//}Time;

typedef struct LNode *PtrToAdjVNode;
struct LNode{
	//Time t;				  //ʱ�� 
	peo p;                    //������
	struct LNode *next;       //ָ����       
};
typedef PtrToAdjVNode List;

peo createStuScore();					//��Ӵ������� 
List Add_data();				        //�������ڵ� 
List addToList(List L,List temp);       //ͷ�巨����ڵ� 
void Show_data(peo temp);				//��ʾ���� 
void Show_Alldata(List L);			    //������ϸ 
void Find(List L);						//��ѯ���� 
void After(List L);				    	//������� 
List Delete(List L);					//�����û� 
void After_1(List L);					//����ȡ�� 
void menu();							//���˵� 
void exit();							//�˳�ϵͳ 
void filewriting(List L);				//�ļ��洢 
List fileread(List L);					//�ļ���ȡ

FILE *fp;                           	//�ļ�
peo Temp;								//������ʱ�ڵ� 
//	  time_t timep;						//ʱ�亯���ڵ� 
//    struct tm *q;
 
int main()
{
	system("color 8E");
	List head=NULL,temp;                //ͷ�ڵ��ʼ��
	int choice; 
	while(1)
	{
		menu();                        	//�˵�
		scanf("%d",&choice);
		switch(choice)
		{
		case 1://��Ӵ�����Ϣ
			temp=Add_data();          	//���봢����Ϣ
			head=addToList(head,temp);	//��������Ϣ��ӽ�ȥ����
			break;
		
		case 6:Show_Alldata(head);break; 

		case 5:Find(head);break;		 
	
		case 3:After(head);break;		 

		case 2:head=Delete(head);break;	 

		case 4:After_1(head);break;		  
			
		case 7:filewriting(head);break;   
		
		case 8:head=fileread(head);break;  

		case 0:exit();break;

		} 
	}
}
peo createStuScore()			//������Ϣ���� 
{
	peo temp_1;
	printf("�����봢������:\n"); 
	scanf("%s",temp_1.name);
	
	printf("�����봢���˺� ��6λ��\n");
	while(strlen(temp_1.card_id)!=6){			//6 λ����Ӵ 
		scanf("%s",temp_1.card_id);
	}
	
	printf("�����봢�����֤���루18λ��\n");
	while(strlen(temp_1.peo_id)!=18){   		//18 λ����Ӵ 	
    	scanf("%s",temp_1.peo_id);
    } 
    printf("�����봢����ϵ�绰\n");
    	scanf("%s",temp_1.phone_num);
		
		temp_1.account=0;						//����Ĭ���˻�Ϊ0
									 
	return temp_1;
}


List Add_data()					// �½�һ���ڵ� ������ɶ�������ĸ�ֵ 
{
	List Node;
	Node=(List)malloc(sizeof(LNode));	//�ڵ�����ڴ�
	Node->p=createStuScore();           	//��ɶԴ�����Ϣ��ֵ
	Node->next=NULL;	
	return Node;                        	//���ؽڵ��ַ
}

//��һ���ڵ���ӵ��б���ȥ�������б��ͷָ��
List addToList(List L,List temp)
{
    /*����ͷ�巨�����������*/
	temp->next=L;    
	L=temp;
	return L;
}

//��ʾ��Ϣ
void Show_data(peo temp)
{
	printf("��������:%s �����˺�: %s ���֤�� : %s ��ϵ�绰: %s �˺����: %.3f\n",temp.name,temp.card_id,temp.peo_id,temp.phone_num,temp.account);
	  
}
//��ʾ���д�����Ϣ
void Show_Alldata(List L)
{
	if(L==NULL)
		printf("û����Ϣ��"); 
	while(L)
	{
		Show_data(L->p);
		L=L->next;
	}
	getchar();getchar();
}

//��ѯ����
void Find(List L)
{
	char pos[10];
    /*���õ��Ǵ���ѧ�Ų�ѯ����Ȼ������������Ĳ�ѯ����*/
	printf("�������ѯ��������:\n");
	scanf("%s",pos);	
	while(L)
	{
		if(!strcmp(L->p.card_id,pos)){				//�ж� ����	
			Show_data(L->p);
			printf("��ѯ�ɹ���\n");
			getchar();getchar();
			return; 
        }
		L=L->next;
	}
	printf("��ѯʧ�ܣ�\n");
    	getchar();getchar();
}

//��������
void After(List L)
{
	char pos[10];
	float money;
    /*���õ��Ǵ����˺ţ���Ȼ������������Ĳ�ѯ����*/
    
//    time(&timep);
//    q =localtime(&timep); //�˺�����õ�tm�ṹ���ʱ�䣬���Ѿ����й�ʱ��ת��Ϊ����ʱ��
	
		
	printf("����Ҫ�����˺�:\n");
	scanf("%s",pos);
	while(L)
	{
		if(!strcmp(L->p.card_id,pos))
		{
			printf("����������\n");
				scanf("%f",&money);
				L->p.account+=money;				
//				L->t.day[]=1900+q->tm_year;
//				L->t.month=1+q->tm_mon;
//				L->t.day=q->tm_mday;
//				L->t.hour=q->tm_hour;
//				L->t.minutes=q->tm_min;
//				L->t.second=q->tm_sec;
				printf("���ɹ�\n");							 
            	getchar();getchar();
				return; 
		}
		L=L->next;
	}
	printf("�洢ʧ��!\n");
	getchar();getchar();
}

//ɾ���ɼ�����
List Delete(List L)
{
	char pos[10];
    /*���õ��Ǵ���ѧ��ɾ������Ȼ������������Ĳ�ѯ����*/
	List temp=L->next;    //ע���ҵ�д��
    List head=L;  
	printf("�����������˺�\n");
	scanf("%s",pos);
	/*���ж�ͷ�ڵ���Ϣ*/
	if(!strcmp(head->p.card_id,pos))
	{
		L=head->next;			//�ҵ���Ϣ�ڵ� �����ҵ���Ϣ�ڵ� ����һ���ڵ� ʵ�ֵ�ַ��� 
		printf("�����ɹ�!\n");
		getchar();getchar();
		return L;
	}
	else{
		
		while(temp)                    
		{
			if(!strcmp(L->p.card_id,pos))           /*�ҵ���Ϣ�ڵ� temp=L->next   head=L */ 
			{                             
				head->next=temp->next;    //�ҵ���Ϣ�ڵ� �����ҵ���Ϣ�ڵ� ����һ���ڵ� ʵ�ֵ�ַ���
                		free(temp);
                		printf("�����ɹ�!\n");
                		getchar();getchar();
				return L;
			}
			else
			temp=temp->next;
		}
	}
	printf("����ʧ��!\n");
    	getchar();getchar();
    	return L;
}

//����ȡ���
void After_1(List L)//���Ӵ�С���� 
{
	char pos[10];
	float money;
    /*���õ��Ǵ����˺ţ���Ȼ������������Ĳ�ѯ����*/
    
//    time(&timep);
//    q =localtime(&timep); //�˺�����õ�tm�ṹ���ʱ�䣬���Ѿ����й�ʱ��ת��Ϊ����ʱ��
	
		
	printf("����Ҫȡ����˺�:\n");
	scanf("%s",pos);
	while(L)
	{
		if(!strcmp(L->p.card_id,pos))
		{
			printf("������ȡ����\n");
				scanf("%f",&money);
				if(L->p.account-money>0){ 
					L->p.account-=money;
					printf("ȡ��ɹ�");
				}					
//				L->t.day[]=1900+q->tm_year;
//				L->t.month=1+q->tm_mon;
//				L->t.day=q->tm_mday;
//				L->t.hour=q->tm_hour;
//				L->t.minutes=q->tm_min;
//				L->t.second=q->tm_sec;
				else
					printf("ȡ��ʧ��");								 
            getchar();getchar();
			return; 
		}
		L=L->next;
	}
	printf("�洢ʧ��!\n");
	getchar();getchar();
}
void menu(){

		system("cls");
		printf("             ���ڴ�����Ŀ����ϵͳ       \n");
		printf("=========================================\n");
		printf("|             1.��������                |\n");
		printf("|             2.��������           	|\n");
		printf("|             3.�������             	|\n");
		printf("|             4.����ȡ��                |\n");
		printf("|             5.����ѯ              	|\n");
		printf("|             6.������ϸ             	|\n");
		printf("|             7.��Ϣ�洢                |\n");
		printf("|             8.��Ϣ��ȡ                |\n");
		printf("|             0.�˳�ϵͳ                |\n");
		printf("=========================================\n");
		printf("����������ѡ��:");
}
void exit(){
	printf("�˳�ϵͳ�ɹ�!");
	exit(0);
}
void filewriting(List L){
	
	fp = fopen("text.txt", "w");    //���ļ������Ұ��ļ�����Ϊ��д״̬
	while(L)
    {
            	fprintf(fp,"%s %s %s %s %f\n",
                	L->p.name,
                	L->p.card_id,
                	L->p.peo_id,
                	L->p.phone_num,
               	    L->p.account);//��������ͷ�����ݴ洢�� text.txt�ļ���ȥ��				                        
            		L=L->next;    
    }
    		printf("�洢��Ϣ�ɹ�"); 
    		fclose(fp);        //�ر��ļ�
}

List fileread(List L){

	fp = fopen("text.txt", "r");    //���ļ������Ұ��ļ�����Ϊ��д״̬
	while(!feof(fp))				//feop һֱ���ļ���Ϣ��� һ��'/0' 
	{ 
		fscanf(fp,"%s %s %s %s %f\n",    	//���ļ���ͷ������text.txt �洢��������ȥ
               		Temp.name,
                	Temp.card_id,
                	Temp.peo_id,
                	Temp.phone_num,
               	   &Temp.account
        );			
		List pe=(List)malloc(sizeof(LNode));       //����һ���½ڵ�
        	pe->p=Temp;                              //�Խڵ㴢����Ϣ��ֵ
        	pe->next=NULL;							  
        	L=addToList(L,pe);                         //ͷ�巨��ӽڵ�
	}
    	fclose(fp);				          //�ر��ļ�
	printf("��ȡ��Ϣ�ɹ�");
	getchar();getchar(); 
    	return L;											
}

