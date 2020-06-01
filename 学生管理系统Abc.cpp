#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct students{
	char name[10];            //����
    int stu_id;               //ѧ��
    char stu_class[15];       //�༶
    float grade[3];           //���ſγɼ�   
}stu;
typedef struct LNode *PtrToAdjVNode;
struct LNode{
	stu s;                    //������
	struct LNode *next;       //ָ����       
};
typedef PtrToAdjVNode List;

stu createStuScore();					//���ѧ������ 
List Add_data();					    //�������ڵ� 
List addToList(List L,List temp);       //ͷ�巨����ڵ� 
void Show_data(stu temp);				//��ʾ���� 
void Show_Alldata(List L);			    //չʾ�������� 
void Find(List L);					    //��ѯ���� 
void After(List L);				    	//�޸����� 
List Delete(List L);					//ɾ������ 
void sort(List L);					    //����  
void menu();						    //���˵� 
void exit();						    //�˳�ϵͳ 
void filewriting(List L);				//�ļ��洢 
List fileread(List L);					//�ļ���ȡ

FILE *fp;                               //�ļ�
stu people;								//ѧ����ʱ�ڵ� 
 
int main()
{
	List head=NULL,temp;               //ͷ�ڵ��ʼ��
	int choice;

	while(1)
	{
		menu();                        //�˵�
		scanf("%d",&choice);
		switch(choice)
		{
		case 1://���ѧ����Ϣ
				temp=Add_data();          //����ѧ����Ϣ
				head=addToList(head,temp);//��ѧ����Ϣ��ӽ�ȥ����
				break;
		
		case 2:Show_Alldata(head);break; 

		case 3:Find(head);break;		 
	
		case 4:After(head);break;		 

		case 5:head=Delete(head);break;	 

		case 6:sort(head);break;		  
			
		case 7:filewriting(head);break;   
		
		case 8:head=fileread(head);break;  

		case 0:exit();break;

		}
	}
}
stu createStuScore()			//ѧ����Ϣ���� 
{
	stu temp;
	printf("������ѧ������:\n"); 
	scanf("%s",temp.name);
	printf("������ѧ��ѧ��\n");
	scanf("%d",&temp.stu_id);
    printf("������ѧ���༶\n");
    scanf("%s",temp.stu_class);
    printf("��ֱ�����ѧ�����ſγ̳ɼ�\n");
    scanf("%f %f %f",&temp.grade[0],&temp.grade[1],&temp.grade[2]);
	return temp;
}


List Add_data()					// �½�һ���ڵ� ������ɶ�������ĸ�ֵ 
{
	List Node;
	Node=(List)malloc(sizeof(LNode));	//�ڵ�����ڴ�
	Node->s=createStuScore();           //��ɶ�ѧ����Ϣ��ֵ
	Node->next=NULL;	
	return Node;                        //���ؽڵ��ַ
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
void Show_data(stu temp)
{
	printf("ѧ������:%s\tѧ��ѧ��:%d\tѧ���༶:%s\tѧ�����ſγ̳ɼ�: %.2f %.2f %.2f\n",
    temp.name,temp.stu_id,temp.stu_class,temp.grade[0],temp.grade[1],temp.grade[2]);
}
//��ʾ����ѧ����Ϣ
void Show_Alldata(List L)
{
	if(L==NULL)
		printf("û����Ϣ��"); 
	while(L)
	{
		Show_data(L->s);
		L=L->next;
	}
	getchar();getchar();
}

//��ѯ����
void Find(List L)
{
	int pos;
    /*���õ���ѧ��ѧ�Ų�ѯ����Ȼ������������Ĳ�ѯ����*/
	printf("�������ѯѧ��ѧ�ű��:\n");
	scanf("%d",&pos);	
	while(L)
	{
		if(pos==L->s.stu_id){				//�ж� ����	
			Show_data(L->s);
			printf("��ѯ�ɹ���\n");
			getchar();getchar();
			return; 
        }
		L=L->next;
	}
	printf("��ѯʧ�ܣ�\n");
    	getchar();getchar();
}

//�޸ĳ�����
void After(List L)
{
	int pos;
    /*���õ���ѧ��ѧ���޸ģ���Ȼ������������Ĳ�ѯ����*/	
	printf("����Ҫ�޸�ѧ��ѧ��:\n");
	scanf("%d",&pos);
	while(L)
	{
		if(pos==L->s.stu_id)
		{
			L->s=createStuScore();    //���´���ѧ����Ϣ������ֵ
            printf("�޸ĳɹ�!\n");
            getchar();getchar();
			return; 
		}
		L=L->next;
	}
	printf("�޸�ʧ��!\n");
	getchar();getchar();
}

//ɾ���ɼ�����
List Delete(List L)
{
	int pos;
    /*���õ���ѧ��ѧ��ɾ������Ȼ������������Ĳ�ѯ����*/
	List temp=L->next;    //ע���ҵ�д��
    List head=L;  
	printf("������ɾ��ѧ��ѧ��\n");
	scanf("%d",&pos);
	/*���ж�ͷ�ڵ���Ϣ*/
	if(pos==head->s.stu_id)
	{
		L=head->next;			//�ҵ���Ϣ�ڵ� �����ҵ���Ϣ�ڵ� ����һ���ڵ� ʵ�ֵ�ַ��� 
		printf("ɾ���ɹ�!\n");
		getchar();getchar();
		return L;
	}
	else{
		
		while(temp)                    
		{
			if(pos==temp->s.stu_id)         /*�ҵ���Ϣ�ڵ� temp=L->next   head=L */ 
			{                             
				head->next=temp->next;    //�ҵ���Ϣ�ڵ� �����ҵ���Ϣ�ڵ� ����һ���ڵ� ʵ�ֵ�ַ���
                free(temp);
                printf("ɾ���ɹ�!\n");
                getchar();getchar();
				return L;
			}
			else
				temp=temp->next;
		}
	}
	printf("ɾ��ʧ��!\n");
    getchar();getchar();
    return L;
}

//����
void sort(List L)//���Ӵ�С���� 
{
	List big,small;	//ͷ�ڵ� ��С�ڵ� 
	
	big=L;
	stu temp;               //ѧ����Ϣ��ʱ�ڵ�
	int grade,grade1;
	
	
	while(big)
	{
		small=big;
		grade=small->s.grade[0]+small->s.grade[1]+small->s.grade[2];
		while(small)
		{
			grade1=small->s.grade[0]+small->s.grade[1]+small->s.grade[2];
			if(grade>grade1)		//��С���� �����ж�  ���������򽻻� 
			{						//���õ���ѡ������ ����֪����ͬѧ��ѡ��������ǰ���н���  
				temp=big->s;
				big->s=small->s;	//����  ѧ����Ϣ ע�� ��������һ�����壡 
				small->s=temp;
			}
			small=small->next;		//�ڲ�ѭ�� 
		}
		big=big->next;				//���ѭ�� 
	}
	printf("����ɹ�!\n");
    getchar();getchar();
}
void menu(){

		system("cls");
		printf("              xxѧ��ϵͳģ��            \n\n");
		printf("=========================================\n");
		printf("|             1.�����Ϣ                |\n");
		printf("|             2.��ʾ������Ϣ            |\n");
		printf("|             3.��ѯ��Ϣ                |\n");
		printf("|             4.�޸���Ϣ                |\n");
		printf("|             5.ɾ����Ϣ                |\n");
		printf("|             6.�ɼ�����                |\n");
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
            	fprintf(fp,"%s %d %s %.2f %.2f %.2f\n",
                L->s.name,
                L->s.stu_id,
                L->s.stu_class,
                L->s.grade[0],
                L->s.grade[1],
                L->s.grade[2]);//��������ͷ�����ݴ洢�� text.txt�ļ���ȥ�� 
                                
            	L=L->next;    
    }
    fclose(fp);        //�ر��ļ�
}

List fileread(List L){

	fp = fopen("text.txt", "r");    //���ļ������Ұ��ļ�����Ϊ��д״̬
	while(!feof(fp))				//feop һֱ���ļ���Ϣ��� һ��'/0' 
	{ 
		fscanf(fp,"%s %d %s %f %f %f\n",    	//���ļ���ͷ������text.txt �洢��������ȥ
                people.name,
                &people.stu_id,
                people.stu_class,
                &people.grade[0],
                &people.grade[1],
                &people.grade[2]
        );			
		List p=(List)malloc(sizeof(LNode));      //����һ���½ڵ�
        p->s=people;                             //�Խڵ�ѧ����Ϣ��ֵ
        p->next=NULL;							  
        L=addToList(L,p);                        //ͷ�巨��ӽڵ�
	}
    fclose(fp);									//�ر��ļ�
	printf("��ȡ�ɹ�");
	getchar();getchar(); 
    return L;											
}

