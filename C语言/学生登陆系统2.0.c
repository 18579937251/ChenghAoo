#include <stdio.h>
#include <string.h>	//C���ַ���������غ�����ͷ�ļ�
#include <stdlib.h>
#include <conio.h>
#define LEN 20 
int Student = -1 ;	//Ĭ��ѧ������Ϊ -1 �� 

struct student{
	int grade;
	char name[20];
};
int main()
{

	
	char password[LEN];		//���ڴ������

	char confirmation[LEN];		//���ڱ���ȷ������

	int tryAgain = 0;				//���ԵĴ���
	char opt;//�˵�ѡ��
	
	//1.��������ϵͳ

	do
	{
		printf("----------��������---------\n");
		printf("��������Ĺ������룺");
		scanf("%s", password);
		printf("��ȷ����Ĺ������룺");
		scanf("%s", confirmation);
	}while(strcmp(password, confirmation));	
			
		printf("�������óɹ����������Ϊ%s\n", password);
		printf("���������ʼ��¼ϵͳ.....\n");
		getch();	//���������������ó���ͣ���ڴˣ�ֱ�����ǰ��¼����ϵ�ĳ������

		system("cls");	//����	
	//2.��¼ϵͳ
	printf("----------��¼ϵͳ---------\n");
		printf("���������룺");
	
	while(scanf("%s", confirmation), strcmp(password, confirmation))
	{
		tryAgain++;	//�ۼ��������ԵĴ���
		//�������ԵĴ�����������������
		if(tryAgain < 3)
			printf("����%d�Σ����������룺", tryAgain);
		else
			break;	//��������������ڵ������Σ��˳�ѭ��

	}
	//3.������
	system("cls");
	//������� ��1���������δ�������� 2��������ȷ������
	printf("----------������---------\n");
	if(tryAgain >= 3)
	{		
		printf("�Բ���3���������ϵͳ�˳���\n");
		exit(-1); //�˳�����
	}else{		
		printf("��ӭ�������ϵͳ��\n");
	}
int Pos,Pos_1; 
int i,j;

struct student s[20]; // ����20ѧ������ 

	while(1){
		main_menu();
		scanf("%d",&Pos);
		switch(Pos){
			case 1:				//ѧ��¼����Ϣ ���� + �ɼ� 
			
				Student++; //ѧ����������1
				printf("������ѧ������\n");
					scanf("%s",s[Student].name);
				printf("������ѧ���ɼ�\n");
					scanf("%d",&s[Student].grade);
				 	
				
				printf("¼��ɹ� ��\n");
				getchar();getchar();			
				break;
			case 2:
				printf("���������ѯ��ѧ�����\n");
				scanf("%d",&Pos_1);
				if(Pos_1>=0&&Pos_1<=Student){
					printf("ѧ������:%s �ɼ� : %d",s[Pos_1-1].name,s[Pos_1-1].grade);
					getchar();
				}else{
					printf("�����ڸ�ѧ����Ϣ��\n");
					getchar(); 
				}
				getchar();	
				break;
			case 3:
				for(i=0;i<=Student;i++){
					for(j=i+1;j<=Student;j++){
						if(s[i].grade>s[j].grade){
							struct student temp= s[i];
							s[i] = s[j];
							s[j] = temp;
						}
					}
				} 
				printf("����ɹ���");
				getchar();getchar();
				break;
			case 4:
				for(i=0;i<=Student;i++){
					printf("ѧ������:%s �ɼ� : %d\n",s[i].name,s[i].grade);
				}
				break; 
				
				
			case 0:
				printf("�˳�ϵͳ�ɹ� ��");
				getchar();getchar(); 
				exit(0);
				break;
				
				
		
		
		}	
	system("cls");	
	}	
	
	return 0;	
}

void  main_menu(){
	printf(".                                ���˵�                               .\n");	
	printf(".......................................................................\n");	
	printf(".                             ѧ������ϵͳ                            .\n"); 
	printf(".                             1.¼��ѧ����Ϣ                          .\n");  
	printf(".                             2.��ѯѧ����Ϣ                          .\n");
	printf(".                             3.����ѧ���ɼ�                          .\n");
	printf(".                             4.��ӡȫ��ѧ���ɼ�                      .\n");
	printf(".                             0.�˳�                                  .\n");
	printf(".......................................................................\n");
}

