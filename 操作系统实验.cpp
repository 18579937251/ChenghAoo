//#include<stdio.h>
//#include<stdlib.h>
//struct Operation{
//
//	char operation[20];
//	int Status;						//����״̬	 
//	int Time_arrival;				//����ʱ�� 
//	int Time_elapsed;				//����ʱ�� 
//	int Time_Start;					//��ʼʱ��
//	int Time_Completion;			//���ʱ��
//	int Turnaround_time;	 		//��תʱ��
//	float _timeWeighted_Turnaround; //��Ȩ��תʱ�� 
//	int Priority;					//���ȼ� 
//};
//typedef struct VNode *PtrToAdjVNode;
//
//struct VNode{
//
//	Operation X;
//	struct VNode *Next;
//};
//typedef PtrToAdjVNode PCB;
//
//PCB CreatProcess(PCB P);
//void Process_Scheduling(PCB P);
//void Process_Short(PCB P);  
//
//int main(){
//	
//	
//	int Pos;
//	
//	PCB P1,P2;
//		
//	P2=CreatProcess(P2); 			//�����ȷ���
//	Process_Scheduling(P2);
//	
//	P1=CreatProcess(P1);			//����ҵ���ȷ�
//	Process_Short(P1);
//
//
//
//	return 0;
//}
//
//PCB CreatProcess(PCB Head){
//
//	int Pos;
//	
//	/*ͷ�������ڴ�
//	���õ���ͷ��㲻����ͨ��β��ָ����ƶ��Ӷ� ������ֵ���б仯 
//	*/
//	Head=(PCB)malloc(sizeof(struct VNode));
//	Head->Next=NULL;
//	PCB P1=NULL;
//	PCB P2=Head; 
//	
//	
//	printf("������������ҵ�� ����״̬ ����ʱ�� ����ʱ�� ���ȼ�\n");
//	scanf("%s %d %d %d %d",Head->X.operation,&Head->X.Status,&Head->X.Time_arrival,&Head->X.Time_elapsed,&Head->X.Priority); 
//	printf("�Ƿ�������� 1 / 0\n");
//	scanf("%d",&Pos);
//	if(Pos==0)
//		return Head; 
//
//	while(1){	
//	P1=(PCB)malloc(sizeof(struct VNode));
//	/*����p1 ���и�ֵ����*/
//	printf("������������ҵ�� ����״̬ ����ʱ�� ����ʱ�� ���ȼ�\n");
//	scanf("%s %d %d %d %d",P1->X.operation,&P1->X.Status,&P1->X.Time_arrival,&P1->X.Time_elapsed,&P1->X.Priority); 
//		
//	P2->Next=P1;		//����βָ�� 
//	P2=P1; 			
//
//	printf("�Ƿ�������� 1 / 0\n");
//	scanf("%d",&Pos);
//	if(Pos==0)
//		break;
//}
//	/*������Ϻ� βָ��ָ��*/ 
//	P2->Next=NULL;
//	 
//	return Head;
//}
//void Process_Scheduling(PCB P){
//
//	PCB M=P;
//	int _Turnaround_time=0,sum=0;
//	float averageLy=0;
//	/*Ĭ�� ��һ����ҵ��ʼʱ��Ϊ 0
//		   ������תʱ��,�����ʱ���������ʱ��
//		   ���Ҵ�Ȩ��תʱ��Ϊ 1	
//	*/
//	M->X.Time_Start=0;		
//	M->X.Turnaround_time=M->X.Time_elapsed;
//	M->X.Time_Completion=M->X.Time_elapsed;
//	M->X._timeWeighted_Turnaround=1;
//	
//	averageLy+=M->X.Turnaround_time;
//	sum++;
//	
//	_Turnaround_time=M->X.Time_Completion;
//	
//	M=M->Next;
//	 
//	while(M){
//		M->X.Time_Start=_Turnaround_time;
//		M->X.Time_Completion=M->X.Time_Start+M->X.Time_elapsed;				//���ʱ�� ���� ��ʼʱ�� + ����ʱ�� 
//		M->X.Turnaround_time=M->X.Time_Completion-M->X.Time_arrival; 		//��תʱ�� ���� ���ʱ�� - ����ʱ��
//		M->X._timeWeighted_Turnaround=M->X.Turnaround_time/(float)(M->X.Time_elapsed);	//��Ȩ��תʱ�� ���� ��תʱ�� / ����ʱ�� 
//		_Turnaround_time=M->X.Time_Completion;
//		/*ƽ����תʱ��*/		
//		averageLy+=M->X.Turnaround_time;
//		sum++;
//		
//		M=M->Next;
//	}
//	
//	printf("-----------------------------�����ȷ���FCFS-----------------------\n");
//	printf("��ҵ  ����ʱ��  ����ʱ��  ��ʼʱ��  ���ʱ��  ��תʱ��  ��Ȩ��תʱ��  \n");
//	while(P){	
//	printf("%s   %5d  	%5d   %5d  	   %5d    %5d  	%5.2f\n",P->X.operation,P->X.Time_arrival,P->X.Time_elapsed
//		,P->X.Time_Start,P->X.Time_Completion
//		,P->X.Turnaround_time,P->X._timeWeighted_Turnaround
//	);
//		P=P->Next;	
//	}
//	printf("ƽ����תʱ��Ϊ:%.2f\n",averageLy/(float)(sum)); 
//	printf("--------------------------------------------------------------------\n"); 
////	while(P){
////		printf("%s\n",P->X.operation);
////		P=P->Next;
////	} 	 
//}
//void Process_Short(PCB P){
//
//	PCB M1=P;
//	/*Ĭ�Ͻ��̶���ͬʱ����� */
//	while(M1){
//		M1->X.Time_arrival=0; 
//		M1=M1->Next;
//	}
//	
//	PCB Small,Big=P;
//	Operation Temp; 
//	int Num1,Num2;
//	
//	/*���õ���ѡ��������ַ�,�ȸ�����ҵ���ʱ���������*/
//	while(Big){		
//		Num1=Big->X.Time_elapsed;
//		Small=Big;
//		while(Small){
//			Num2=Small->X.Time_elapsed;
//			if(Num1>Num2){
//				Temp=Big->X;			// ע������ѧ����ʱ�ڵ���Ϊ������	
//				Big->X=Small->X;
//				Small->X=Temp;
//			}
//			Small=Small->Next;
//		}
//		Big=Big->Next;
//	}
//	
//	PCB M=P;
//	int _Turnaround_time=0,sum=0;
//	float averageLy=0;
//	/*Ĭ�� ��һ����ҵ��ʼʱ��Ϊ 0
//		   ������תʱ��,�����ʱ���������ʱ��
//		   ���Ҵ�Ȩ��תʱ��Ϊ 1	
//	*/
//	M->X.Time_Start=0;		
//	M->X.Turnaround_time=M->X.Time_elapsed;
//	M->X.Time_Completion=M->X.Time_elapsed;
//	M->X._timeWeighted_Turnaround=1;
//	
//	averageLy+=M->X.Turnaround_time;
//	sum++;
//	
//	_Turnaround_time=M->X.Time_Completion;
//	
//	M=M->Next;
//	 
//	while(M){
//		M->X.Time_Start=_Turnaround_time;
//		M->X.Time_Completion=M->X.Time_Start+M->X.Time_elapsed;				//���ʱ�� ���� ��ʼʱ�� + ����ʱ�� 
//		M->X.Turnaround_time=M->X.Time_Completion-M->X.Time_arrival; 		//��תʱ�� ���� ���ʱ�� - ����ʱ��
//		M->X._timeWeighted_Turnaround=M->X.Turnaround_time/(float)(M->X.Time_elapsed);	//��Ȩ��תʱ�� ���� ��תʱ�� / ����ʱ�� 
//		_Turnaround_time=M->X.Time_Completion;
//		/*ƽ����תʱ��*/		
//		averageLy+=M->X.Turnaround_time;
//		sum++;
//		
//		M=M->Next;
//	}
//	
//	printf("------------------------------����ҵ���ȷ�SJF-----------------------------\n");
//	printf("��ҵ  ����ʱ��  ����ʱ��  ��ʼʱ��  ���ʱ��  ��תʱ��  ��Ȩ��תʱ��  \n");
//	while(P){	
//	printf("%s   %5d  	%5d   %5d  	   %5d    %5d  	%5.2f\n",P->X.operation,P->X.Time_arrival,P->X.Time_elapsed
//		,P->X.Time_Start,P->X.Time_Completion
//		,P->X.Turnaround_time,P->X._timeWeighted_Turnaround
//	);
//		P=P->Next;	
//	}
//	printf("ƽ����תʱ��Ϊ:%.2f\n",averageLy/(float)(sum));
//	printf("--------------------------------------------------------------------\n");
//
//} 
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//#include<unistd.h>
//#include<pthread.h>
//#include<semaphore.h>
//
//#define P sem_wait
//#define V sem_post
//#define apple_full &fullA
//#define orange_full &fullB
//#define empty &emptyA

//sem_t fullA;
//sem_t fullB;
//sem_t emptyA;
//
//void * Father(void *p); 
//void * Mother(void *p);
//void *Daughter(void *p);
//void *Son(void *p);
//
//int sum=999;
//int Pos=0; 
//int main(){
//
//	sem_init(apple_full,0,0);
//	sem_init(orange_full,0,0);
//	sem_init(empty,0,1);
//	
//	pthread_t tcb0;		 
//	pthread_t tcb1;
//	pthread_t tcb2;
//	pthread_t tcb3;
//	
//	/*�������� ���� ĸ�� Ů�� ����*/ 
//	pthread_create(&tcb0,NULL,Father,NULL);
//	pthread_create(&tcb1,NULL,Mother,NULL);
//	pthread_create(&tcb2,NULL,Daughter,NULL);
//	pthread_create(&tcb3,NULL,Son,NULL);
//	
//	
//	pthread_exit(0);
//	return 0;
//} 
//void * Father(void *p){
//
//	while(Pos<=sum){
//		P(empty);					//��ʾ����ƻ�����뻺����		
//		printf("���������ӷ�ƻ��\n%d ��\n",Pos);
//		V(apple_full);				//����ƻ��
//		Pos++; 
//	}
//}
//void * Mother(void *p){
//
//	while(Pos<=sum){
//		P(empty);					//��ʾĸ��ˮ�����뻺���� 
//		printf("ĸ�������ӷ�����\n%d ��\n",Pos);
//		V(orange_full);
//		Pos++;
//	}
//}
//
//void *Daughter(void *p){
//
//	while(Pos<=sum){	
//		P(apple_full);				//��ʾ �鿴 ƻ���Ƿ��� ������  
//		printf("Ů��������ȡƻ��\n%d ��\n",Pos);
//		V(empty);					//Ů�� ȡ��ƻ�� 
//		Pos++;
//	}
//
//} 
//void *Son(void *p){
//
//	while(Pos<=sum){
//	
//		P(orange_full);				//��ʾ �鿴 �����Ƿ��� ������
//		printf("����������ȡ����\n%d ��\n",Pos);
//		V(empty);					//���� ȡ������
//		Pos++; 
//	}
//} 
 
#include <iostream>
using namespace std; 
//ȫ�ֱ�������
int Available[100]; 	  //��������Դ��Ŀ 
int Max[50][100];   	  //��M������ �����Դ����  
int Allocation[50][100];  //��M������ �������Դ�� 
int Need[50][100];        //�� M�����̻���ҪN����Դ����Դ��
int Request[50][100];     //�� M�����̷�������N�� ��Դ����Դ��
int Finish[50];
int p[50];				  //��¼��ȫ���� 
int m,n;   				  //M������,N����Դ
//��ȫ���㷨
int SecuritY()                      
{
    int i,j,l=0;
    int Work[100]; //��������Դ����
    
    for (i=0;i<n;i++)
        Work[i]=Available[i];
        
    for (i=0;i<m;i++)
        Finish[i]=0;
     
	/*ͨ�� i ��Ӧ��M���������� ���Ƿ���̴��ڰ�ȫ״̬*/    
    for (i=0;i<m;i++)	 
    {
        if (Finish[i]==1)	
        continue;
        else
        {
            for (j=0;j<n;j++)
            {
                if (Need[i][j]>Work[j])
                    break;
            }
            if (j==n)
            {
                Finish[i]=1;
                for(int k=0;k<n;k++)
                    Work[k]+=Allocation[i][k];
                p[l++]=i;
                i=-1;
            }
            else continue;
        }
    }
    if (l==m)
        {
            cout<<"ϵͳ�ǰ�ȫ��"<<'\n';
            cout<<"ϵͳ��ȫ������:\n";
            for (i=0;i<l;i++)
            {
                cout<<p[i];
                if (i!=l-1)
                    cout<<"-->";
            }
            cout<<'\n';
            return 1;
        }
    else{
		cout<<"ϵͳ�ǲ���ȫ��"<<'\n';
		cout<<'\n';
		return 0; 
	}
}
//���м��㷨
int main()
{
    int i,j,mi;
    cout<<"������̵���Ŀ:\n";
    cin>>m;
    cout<<"������Դ������:\n";
    cin>>n;
    cout<<"����ÿ�������������ĸ�����Դ��,����"<<m<<"x"<<n<<"��������\n";
    for (i=0;i<m;i++)
        for(j= 0;j<n;j++)
            cin>>Max[i][j];
    cout<<"����ÿ�������Ѿ�����ĸ�����Դ��,����"<<m<<"x"<<n<<"��������\n";
    for (i=0;i<m;i++){ 
        for(j=0;j<n;j++){       
            cin>>Allocation[i][j];
            Need[i][j]=Max[i][j]-Allocation[i][j];	//�� i ����Դ��Ҫ�Ľ����� 
            if (Need[i][j]<0){  					//�ж��Ƿ�������ȷ 
                cout<<"������ĵ�"<<i+1<<"��������ӵ�еĵ�"<<j+1<<"����Դ��������������:\n";
                j--;
                continue;
            }
        }
    }
    cout<<"�����������Դ���е���Ŀ:\n";
    for (i=0;i<n;i++)
    	cin>>Available[i];
    SecuritY();
    
    while (1)
    {
        cout<<"����Ҫ�������Դ�Ľ��̺ţ�����һ�����̺�Ϊ0���ڶ������̺�Ϊ1���������ƣ�\n";
        cin>>mi;
        cout<<"�������������ĸ�����Դ������\n";
        for (i=0;i<n;i++)
        cin>>Request[mi][i];		
        for (i=0;i<n;i++)
        {

            if (Request[mi][i]>Need[mi][i])
            {
                cout<<"��������Դ���������̵���������\n";
                return 0;
            }
            if (Request[mi][i]>Available[i])
            {
                cout<<"��������Դ������ϵͳ���е���Դ����\n";
                return 0;
            }
        }
        for (i=0;i<n;i++)
        {
            Available[i]-=Request[mi][i];
            Allocation[mi][i]+=Request[mi][i];
            Need[mi][i]-=Request[mi][i];
        }
        if (SecuritY())
            cout<<"ͬ���������\n";
        else
        {
            cout<<"������󱻾ܾ���\n";
            for (i=0;i<n;i++)
            {
                Available[i]+=Request[mi][i];
                Allocation[mi][i]-=Request[mi][i];
                Need[mi][i]+=Request[mi][i];
            }
        }
        for (i=0;i<m;i++) 
            Finish[i]=0;
        char Flag;       //��־λ
        cout<<"�Ƿ��ٴ�������䣿���밴Y/y�����밴N/n";
        while (1)
        {
            cin>>Flag;
            if (Flag=='Y'||Flag=='y'||Flag=='N'||Flag=='n')
            break;
            else
            {
                cout<<"�밴Ҫ����������:\n";
                continue;
            }
        }
        if (Flag=='Y'||Flag=='y')
        continue;
        else break;
    }
}

