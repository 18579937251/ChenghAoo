#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
#define N 6		//����༶��6����		/*��������е��޸�*/ 
#define M 3 	//������3�ųɼ� 		//���ζ�Ӧ  math english C 
 
typedef struct student{
    int stu_number;  	 				//ѧ�� 
    char stu_name[12];			        //���� 
    float grade[M];						//�ɼ�
}stu;
//˳���Ĺ���
typedef struct LNode *PtrToAdjVNode;
struct LNode{
    int last;				                //ָ�����һ��Ԫ���±� 
    stu *array;								//ѧ��ָ������ 
};
typedef PtrToAdjVNode List;
 
stu temp;   							        //ѧ��ȫ�ֱ���
FILE *fp;        
List MakeEmpty();								//˳���ĳ�ʼ�� 
void AllInsert(List L);							//������ѧ����Ϣ 
void Show(List L);								//չʾ������Ϣ
void FILeWrite(List L);							//ѧ����Ϣ����
void After(List L);								//˳���İ�����޸�  
void Sort(List L);								//��ѧ�� ��ѧ���ɼ���������
void AchieveMent_statistics(List L);  			//�ɼ�ͳ�� 

void login();							        //������Ϣ 

	  
                   
int main(){

	List L=MakeEmpty(); //˳���ĳ�ʼ�� 
	int option;	
	while(1){
		login();				//��ʾ���� 
		scanf("%d",&option); 	
		system("cls");			        //�������� 	
		switch(option)
		{
			case 1:
				AllInsert(L); 				
				break; 
			case 2:
				Show(L);
               	break;
			case 3:
				FILeWrite(L);
				break;
			case 4:
                Sort(L);
				break;
			case 5:
                After(L);				
				break;
            case 6:
  				AchieveMent_statistics(L);
  				break;
  				
			case 7:
            	exit(0);
				break;
			default:
				printf("�����ʽ���󣡣���\n�����������...\n"); 
				getchar();
				break;
			 
		} 
		system("cls");
	}  
    return 0;
} 
List MakeEmpty(){
	List L;
		L=(List)malloc(sizeof(struct LNode));		//��ָ������ڴ� 
    	L->array=(stu*)malloc(sizeof(stu)*MAXSIZE);	//��ѧ���������ռ� 
    	L->last=-1;									//��ʱ��û��ѧ��,����ʼֵָ��-1 
	return L;  
}

//˳���İ���Ų�ѯ
void  Find(List L){
	//��ֻ��д����Ų�ѯ����Ȼ���ǿ��԰����� ѧ�ŵȲ�ѯ 
        int index;
        printf("��������Ҫ��ѯѧ���ı��:\n");
        scanf("%d",&index);
        if(index>=0&&index<=L->last){
	printf("ѧ��:%d ����:%s �ɼ�: Math English C %.2f %.2f %.2f\n",
		L->array[index].stu_number,
		L->array[index].stu_name,
		L->array[index].grade[0],
		L->array[index].grade[1],
		L->array[index].grade[2]
		);
	}
	else{
		printf("��ѯʧ��");
		getchar();getchar();
		return; 		   
		}
        getchar();getchar();
} 
//˳������ʾ
void Show(List L)
{
	for(int i=0;i<=L->last;i++){
		printf("ѧ��:%d ����:%s Math: %.2f English: %.2f C: %.2f\n",
		L->array[i].stu_number,
		L->array[i].stu_name,
		L->array[i].grade[0],
		L->array[i].grade[1],
		L->array[i].grade[2]
		);
	}
	getchar();getchar();
}   
//˳�����޸�    
void After(List L){
	//��ֻ��д������޸ģ���Ȼ���ǿ��԰����� ѧ�ŵȲ�ѯ
	int index;
	stu Temp;
		printf("������ѧ��: "); 
		scanf("%d",&Temp.stu_number); 
		printf("����������:"); 
		scanf("%s",Temp.stu_name); 
		printf("������ɼ�: ���������� Math English C \n");
		scanf("%f %f %f",&Temp.grade[0],&Temp.grade[1],&Temp.grade[2]);
		
		printf("��������Ҫ�޸�ѧ���ı��:");
        scanf("%d",&index);
    if(index>=0&&index<=L->last){ 
        L->array[index]=Temp;
        printf("�޸ĳɹ�����");
    } 
        
    else{
        printf("�޸�ʧ��");
	return; 		   
	}
   	getchar();getchar(); 
}
//ѧ������ϵͳ��ʾ����                  
void login()
{
	printf("\n		��ӭ�����༶�ɼ�����ϵͳ\n");
	printf("	=====================================\n");
	printf("	|  1���ɼ�¼��                      |\n");
	printf("	|                                   |\n");
	printf("	|  2���ɼ���ʾ                      |\n");
	printf("	|                                   |\n");
	printf("	|  3���ɼ�����                      |\n");
	printf("	|                                   |\n");
	printf("	|  4���ɼ�����                      |\n");
	printf("	|                                   |\n");
	printf("	|  5���ɼ��޸�                      |\n");
	printf("	|                                   |\n");
   	printf("	|  6���ɼ�ͳ��                      |\n");
   	printf("	|                                   |\n");
	printf("	|  7���˳�ϵͳ                      |\n");
	printf("	=====================================\n");
	printf("\n\n��������Ĳ�����");
}
void Sort(List L){
							// ע�� ���ǰ���ѧ���ܳɼ��������� 
	int i,j;
	float temp1,temp2;
	for(i=0;i<=L->last;i++){
			temp1=(L->array[i].grade[0]+L->array[i].grade[1]+L->array[i].grade[2]);
		for(j=i+1;j<=L->last;j++){
			temp2=(L->array[j].grade[0]+L->array[j].grade[1]+L->array[j].grade[2]);
			if(temp1>temp2){	//��ѡ����ǰ���ѡ��������е�	
				temp=L->array[i];
				L->array[i]=L->array[j];
				L->array[j]=temp;		
			} 
	}	
}
	printf("����ɹ�\n");
	for(i=0;i<=L->last;i++){
		temp1=L->array[i].grade[0]+L->array[i].grade[1]+L->array[i].grade[2];
		printf("ѧ��:%d ����:%s �ܳɼ�:%.2f\n",
		L->array[i].stu_number,
		L->array[i].stu_name,
		temp1
		);
	}
	getchar();getchar();
}
void AllInsert(List L){

	int i,j;
	if(L->last==N-1){
		printf("ȫ��ѧ���ɼ��Ѿ�¼ȡ���\n");
		getchar();getchar();
		return;
	}
	for(j=0;j<N;j++){
		++L->last;
		printf("�������%d��ѧ����Ϣ\n",j+1);		
		printf("������ѧ�ţ�\n"); 
		scanf("%d",&L->array[L->last].stu_number); 
		printf("������������\n"); 
		scanf("%s",L->array[L->last].stu_name); 
		printf("������ɼ������������� Math English C\n");
		scanf("%f %f %f",&L->array[L->last].grade[0],&L->array[L->last].grade[1],&L->array[L->last].grade[2]);
		system("cls");	
	} 
	printf("��ӳɼ���Ϣ��ϣ�\n");
	getchar();getchar();
} 
void FILeWrite(List L){
	int i;
	/*д���ļ�����*/
    if(L->last==-1){            		//˵����ʱû��ѧ������
        printf("�洢ѧ����Ϣʧ��");
        getchar();getchar(); 
        return;
        }
        
    fp = fopen("text.txt", "w");     	//���ļ������Ұ�������Ϊ��д״̬
    for(i=0;i<=L->last;i++){     	//���ΰ�����ѧ����Ϣ����text.txt
        fprintf(fp,"ѧ��: %d ����: %s Math: %.2f English: %.2f C: %.2f\n",
            L->array[i].stu_number,
            L->array[i].stu_name,
            L->array[i].grade[0],
            L->array[i].grade[1],
            L->array[i].grade[2]);
    }
        fclose(fp);                  	//�ر��ļ�
        printf("�洢ѧ����Ϣ�ɹ�!");
        getchar();getchar(); 

}
void AchieveMent_statistics(List L){

	int i,Pos,temp1=0,temp2=0,temp3=0,index1,index2,index3;
	float average1=0,average2=0,average3=0,Highest1=-99999,Highest2=-99999,Highest3=-99999;	
	for(i=0;i<=L->last;i++){
		
		average1+=L->array[i].grade[0];
		average2+=L->array[i].grade[1];			//ƽ���ɼ� 
		average3+=L->array[i].grade[2];
		
		if(L->array[i].grade[0]>Highest1){
			Highest1=L->array[i].grade[0];	
			index1=i;
		}
		if(L->array[i].grade[1]>Highest2){		//��߳ɼ� 
			Highest2=L->array[i].grade[1];
			index2=i;
		}
		if(L->array[i].grade[2]>Highest3){
			Highest1=L->array[i].grade[2];
			index3=i;
		}   
	
	}
		average1=average1/6.0;					//�γ�Math����ƽ���ɼ�
		average2=average3/6.0;					//�γ�English����ƽ���ɼ�
		average3=average3/6.0;					//�γ�C����ƽ���ɼ�
		
		for(i=0;i<=L->last;i++){
			
			if(L->array[i].grade[0]>average1)	//����ƽ���� ���� 
				temp1++;
			if(L->array[i].grade[1]>average2)	
				temp2++;
			if(L->array[i].grade[2]>average3)	
				temp3++;				
		}		 	
	printf("������ɼ�ͳ������:\n1, ��ʾÿ�ſγ̳ɼ���ߵ�ѧ���Ļ�����Ϣ\n2, ��ʾÿ�ſγ̵�ƽ���ɼ�\n3,��ʾ����ĳ�ſγ�ƽ���ɼ���ѧ������: \n");
		scanf("%d",&Pos);
		if(Pos==1){
				printf("Math��߳ɼ�����Ϣ ѧ��:%d ����:%s �ɼ�: Math English C %.2f %.2f %.2f\n",
				L->array[index1].stu_number,
				L->array[index1].stu_name,
				L->array[index1].grade[0],
				L->array[index1].grade[1],
				L->array[index1].grade[2]
				);
				printf("English��߳ɼ�����Ϣ ѧ��:%d ����:%s �ɼ�: Math: %.2f English: %.2f C: %.2f\n",
				L->array[index2].stu_number,
				L->array[index2].stu_name,
				L->array[index2].grade[0],
				L->array[index2].grade[1],
				L->array[index2].grade[2]
				);
				printf("C������߳ɼ�����Ϣ ѧ��:%d ����:%s �ɼ�: Math English C %.2f %.2f %.2f\n",
				L->array[index3].stu_number,
				L->array[index3].stu_name,
				L->array[index3].grade[0],
				L->array[index3].grade[1],
				L->array[index3].grade[2]
				);	
		}
		if(Pos==2){
				printf("ÿһ�ſ�ƽ���ɼ��ֱ�ΪMath: %.2f English: %.2f C: %.2f",average1,average2,average3);	
		}
		if(Pos==3){
				printf("����ÿ�ſγ�ƽ���ɼ��������ֱ�Ϊ Math: %d English: %d C: %d",temp1,temp2,temp3);		
		} 
		
	getchar();getchar();
} 
