#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Commodity{		//��Ʒ���� 
	char name[15];				//���� 
	char Manufacturer[15]; 		//�������� 
	char Model[10];				//�ͺ�
	char Specifiication[15];	//��� 
}Com;
struct Time{
	
	int Year;					//�� 
	int month;					//�� 
	int Day;					//��
	int hour;					//Сʱ
	int minute;					//���� 
};
typedef struct OtherProperties{
	
	int number;					//��Ʒ���� 
	char Warehousing_unit[30];	//��ⵥλ 
	char Delivery_unit[30];		//���ⵥλ 
	char Delivery_boy[15];		//�ͻ�Ա 
	char Pick_up_boy[15];		//���Ա 
}Other;   
typedef struct LNode *PtrToAdjVNode;
struct LNode{
	Com c;
	Time t;					  //������
	Other s;                  
	struct LNode *next;       //ָ����       
};
typedef PtrToAdjVNode List;

Com createComScore();					//�����Ϣ 
Time createTimeScore();
Other createOtherScore();


List Add_data();				        //�������ڵ� 
List addToList(List L,List temp);       //ͷ�巨����ڵ� 
void Show_Alldata(List L);			    //չʾ�������� 
void Find(List L);						//��ѯ���� 
void After(List L);				    	//�޸����� 
List Delete(List L);					//ɾ������

 
Com createComScore();
Time createTimeScore();
Other createOtherScore();

void Show_Commodity(Com temp);
void Show_Time(Time temp);
void Show_Other(Other temp);

void menu();							//���˵� 
void exit();							//�˳�ϵͳ 
void filewriting(List L);				//�ļ��洢 
List fileread(List L);					//�ļ���ȡ

FILE *fp1,*fp2,*fp3;                    //�ļ�
Com C;									
Time T;									//��ʱȫ�ֽڵ�
Other O;
 
int main()
{
	List head=NULL,temp;                //ͷ�ڵ��ʼ��
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

		case 6:	break;		  
			
		case 7:filewriting(head);break;   
		
		case 8:head=fileread(head);break;  

		case 0:exit();break;

		}
	}
}
Com createComScore()			 
{
	printf("��������Ʒ����: ");
	scanf("%s",C.name);
	printf("��������Ʒ��������: ");
	scanf("%s",C.Manufacturer);
	printf("��������Ʒ�ͺ�: ");
	scanf("%s",C.Model);
	printf("��������Ʒ���: ");
	scanf("%s",C.Specifiication); 
	return C;
}
Time createTimeScore(){
	
	printf("��������Ʒ���ʱ�� �밴 �� �� �� Сʱ ����\n");
	scanf("%d.%d.%d.%d.%d",&T.Year,&T.month,&T.Day,&T.hour,&T.minute);
	return T;	
}
Other createOtherScore(){

	printf("��������Ʒ����: ");
	scanf("%d",&O.number);
	printf("��������Ʒ��ⵥλ: ");
	scanf("%s",O.Warehousing_unit);
	printf("��������Ʒ���ⵥλ: ");
	scanf("%s",O.Delivery_unit);
	printf("�������ͻ�Ա����: ");
	scanf("%s",O.Delivery_boy);
	printf("���������Ա����: ");
	scanf("%s",O.Pick_up_boy);
	return O;
}

List Add_data()					// �½�һ���ڵ� ������ɶ�������ĸ�ֵ 
{
	List Node;
	Node=(List)malloc(sizeof(struct LNode));	//�ڵ�����ڴ�
	Node->c=createComScore();           		//��ɶ���Ϣ��ֵ
	Node->t=createTimeScore();
	Node->s=createOtherScore();
	
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
void Show_Commodity(Com temp){

	printf("��Ʒ����: %s ��������: %s �ͺţ� %s ���: %s",temp.name,temp.Manufacturer,temp.Model,temp.Specifiication);
}
void Show_Time(Time temp){

	printf(" ʱ�� %d.%d.%d.%d:%d",temp.Year,temp.month,temp.Day,temp.hour,temp.month);
}
void Show_Other(Other temp){

	printf(" ��Ʒ����: %d ��ⵥλ: %s ���ⵥλ: %s �ͻ�Ա: %s ���Ա: %s\n",temp.number,temp.Warehousing_unit,temp.Delivery_unit,temp.Delivery_boy,temp.Pick_up_boy);
}
//��ʾ����ѧ����Ϣ
void Show_Alldata(List L)
{
	if(L==NULL)
		printf("û����Ϣ��"); 
	while(L)
	{
		Show_Commodity(L->c);
		Show_Time(L->t);
		Show_Other(L->s);
		L=L->next;
	}
	getchar();getchar();
}

//��ѯ����
void Find(List L)
{
	int Pos;
	printf("�������ѯ��ʽ 1.��Ʒ���Ʋ�ѯ	2.��������ڲ�ѯ\n");
	scanf("%d",&Pos);
	if(Pos==1){
		printf("��������Ʒ����: \n");
		scanf("%s",C.name);
		while(L){
		
			if(strcmp(C.name,L->c.name)==0){
				Show_Commodity(L->c);
				Show_Time(L->t);
				Show_Other(L->s);
				getchar();getchar();
				return;			
			}
				L=L->next;		
		}
	
	}
	if(Pos==2){
		printf("��������Ʒ���ʱ�� �밴 �� �� �� Сʱ ����\n");
		scanf("%d.%d.%d.%d.%d",&T.Year,&T.month,&T.Day,&T.hour,&T.minute);
		while(L){
		
			if(L->t.Year==T.Year&&L->t.month==T.month&&L->t.Day==T.Day&&L->t.hour==T.hour&&L->t.minute==T.minute){
				Show_Commodity(L->c);
				Show_Time(L->t);
				Show_Other(L->s);
				getchar();getchar();
				return;			
			}
				L=L->next;		
		}
		printf("δ��ѯ����");	
	}
		getchar();getchar();
}

//�޸ĳ�����
void After(List L)
{
	char Temp[15]; 
    /*���õ���ѧ��ѧ���޸ģ���Ȼ������������Ĳ�ѯ����*/	
	printf("��������޸���Ʒ����:\n");
	scanf("%s",Temp);
	while(L)
	{
		if(strcmp(Temp,L->c.name)==0)
		{
					L->c=createComScore();    //���´�����Ϣ������ֵ
					L->t=createTimeScore();
					L->s=createOtherScore();					
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
	char Temp[15];

	List temp=L->next;    //ע���ҵ�д��
    List head=L;  
	printf("������ɾ����Ʒ����\n");
	scanf("%s",Temp);
	/*���ж�ͷ�ڵ���Ϣ*/
	if(strcmp(Temp,L->c.name)==0)
	{
		L=head->next;			//�ҵ���Ϣ�ڵ� �����ҵ���Ϣ�ڵ� ����һ���ڵ� ʵ�ֵ�ַ��� 
		printf("ɾ���ɹ�!\n");
		getchar();getchar();
		return L;
	}
	else{
		
		while(temp)                    
		{
			if(strcmp(Temp,L->c.name)==0)           /*�ҵ���Ϣ�ڵ� temp=L->next   head=L */ 
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
void menu(){

		system("cls");
		printf("   	           ������ʹ���ϵͳ            \n");
		printf("	====================================\n");
		printf("	|            1.¼����Ʒ��Ϣ	   |\n");
		printf("	|            2.��ʾ������Ϣ	   |\n");
		printf("	|            3.��ѯ��Ʒ��Ϣ	   |\n");
		printf("	|            4.�޸���Ʒ��Ϣ	   |\n");
		printf("	|            5.ɾ����Ʒ��Ϣ	   |\n");
		printf("	|            7.��Ʒ��Ϣ�洢	   |\n");
		printf("	|            8.��Ʒ��Ϣ��ȡ	   |\n");
		printf("	|            0.�˳�ϵͳ    	   |\n");
		printf("	====================================\n");
		printf("����������ѡ��:");
}
void exit(){
	printf("�˳�ϵͳ�ɹ�!");
	exit(0);
}
void filewriting(List L){
	
	fp1 = fopen("��Ʒ.txt", "w");    //���ļ������Ұ��ļ�����Ϊ��д״̬
	fp2 = fopen("ʱ��.txt", "w");
	fp3 = fopen("��Ʒ����.txt", "w"); 
	while(L)
    {
            	fprintf(fp1,"%s %s %s %s\n",
                	L->c.name,
					L->c.Manufacturer,
					L->c.Model,
					L->c.Specifiication
				);
				fprintf(fp2,"%d %d %d %d %d\n",
                	L->t.Year,
					L->t.month,
					L->t.Day,
					L->t.hour,
					L->t.minute
				);
				fprintf(fp3,"%d %s %s %s %s\n",
                	L->s.number,
					L->s.Warehousing_unit,
					L->s.Delivery_unit,
					L->s.Delivery_boy,
					L->s.Pick_up_boy
				);
                                
            	L=L->next;    
    }
    		fclose(fp1);        //�ر��ļ�
    		fclose(fp2);
    		fclose(fp3);
    	printf("д���ļ��ɹ�!\n");	
    	getchar();getchar();
}

List fileread(List L){

	fp1 = fopen("��Ʒ.txt", "r");    //���ļ������Ұ��ļ�����Ϊ��д״̬
	fp2 = fopen("ʱ��.txt", "r");
	fp3 = fopen("��Ʒ����.txt", "r");
	while(!feof(fp1)&&!feof(fp2)&&!feof(fp3))				//feop һֱ���ļ���Ϣ��� һ��'/0' 
	{ 
				fscanf(fp1,"%s %s %s %s\n",
                	C.name,
					C.Manufacturer,
					C.Model,
					C.Specifiication
				);
				fscanf(fp2,"%d %d %d %d %d\n",
                	&T.Year,
					&T.month,
					&T.Day,
					&T.hour,
					&T.minute
				);
				fscanf(fp3,"%d %s %s %s %s\n",
                	&O.number,
					O.Warehousing_unit,
					O.Delivery_unit,
					O.Delivery_boy,
					O.Pick_up_boy
				);	
	
	
	
		List p=(List)malloc(sizeof(LNode));       //����һ���½ڵ�
        	p->c=C;                               //�Խڵ���Ϣ��ֵ
        	p->t=T;
        	p->s=O;
        	
        	p->next=NULL;							  
        	L=addToList(L,p);                         //ͷ�巨��ӽڵ�
	}
    	fclose(fp1);				          			//�ر��ļ�
    	fclose(fp2);
    	fclose(fp3);
		printf("��ȡ�ɹ�!");
		getchar();getchar(); 
    	return L;											
}

