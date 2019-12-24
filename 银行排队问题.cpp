#include<stdio.h>
#include<stdlib.h>
#define MaxProc 9999
#define MaxWindow 100
typedef struct People ElementType;
struct People{
	int T;//�˿͵���ʱ�� 
	int P;//�˿�������ʱ�� 
};
typedef int Position;

struct QNode{
	ElementType *Data;
	Position Front,Rear;
	int Maxsize;
};
typedef struct QNode *Queue;

Queue CreateQueue(int MaxSize);
bool IsFull(Queue Q);
bool IsEmpty(Queue Q);
bool AddQ(Queue Q,ElementType X);
ElementType DeleteQ(Queue Q);
void QueueingAtBank(Queue Q,int N);
void FindNextWindow(int W[],int K,int *waitTime);

int main(){
	int N;
	Queue Q;
	int i;
	ElementType X;
	scanf("%d", &N);
	Q=CreateQueue(N);
	
	for(i=0;i<N;i++){
		scanf("%d%d", &X.T, &X.P);
		AddQ(Q,X);
	}
	QueueingAtBank(Q,N);		
	return 0;
}
Queue CreateQueue(int MaxSize){
	
	Queue Q=(Queue)malloc(sizeof(struct QNode));
	Q->Data=(ElementType*)malloc(MaxSize*sizeof(ElementType));
	Q->Front=Q->Rear=-1;
	Q->Maxsize=MaxSize;
	return Q;
}
bool IsEmpty(Queue Q){
	
	return(Q->Front==Q->Rear);
}
bool IsFull(Queue Q){
	
	return((Q->Rear+1)%Q->Maxsize==Q->Front);
}
bool AddQ(Queue Q,ElementType X){
	
	if(IsFull(Q)){
		printf("������");
		return false;
	}
	else{
		Q->Rear=(Q->Rear+1)%Q->Maxsize;
		Q->Data[Q->Rear]=X; 
		return true;
	}	
}
ElementType DeleteQ(Queue Q){

	Q->Front=(Q->Front+1)%Q->Maxsize;
	return Q->Data[Q->Front]; 
//	}
}
void QueueingAtBank(Queue Q,int N){
	struct People Next;
	int K;					//������ 
	int TotalTime=0;		//�ܵȴ�ʱ�� 
	int CurrentTime=0;		//��ǰʱ�� 
	int Window[MaxWindow];	//Ӫҵ������Ҫ���������ʱ�䳤�� 
	int WaitTime=0;			//�������δ��ڿ���֮�����ȴ���ʱ�� 
	int WinAvail;			//���д���λ��
	
	int temp[MaxWindow];
	//
	int MaxTime=0;	 		//��ȴ�ʱ�� 
	int FinishTime=0;		//������ʱ�� 

	int i,j;
	
	scanf("%d",&K);//������
	
	
	//	 T;//�˿͵���ʱ�� 
	//	 P;//�˿�������ʱ��
	// 1��	
	//������С�ڴ�������ʱ�� 
	if(N<K){
	for(i=0;i<N;i++){
		if(FinishTime<Q->Data[i].P+Q->Data[i].T)
		FinishTime=Q->Data[i].P+Q->Data[i].T;  			//������ʱ���û�����ʱ��+�˿ʹ���ʱ�� 
	}
		printf("ƽ���ȴ�ʱ�� = %.1f minute(s)\n��ȴ�ʱ��%d\n������ʱ��%d\n",0,0,FinishTime);
	for(i=0;i<N;i++)
	 	printf(" 1 ");
	 	printf(" 0 ");
	return;
}
						//�����������ڴ�������ʱ�� 
	for(i=0;i<K;i++){
		Window[i]=0;	//���ڳ�ʼ��Ϊ0 
		temp[i]=0;
	}
//	MaxTime=0;
	
//	 T;//�˿͵���ʱ�� 
//	 P;//�˿�������ʱ�� 
	//2��		
	while(!IsEmpty(Q)){
		
		FindNextWindow(Window,K,&WaitTime);		//Ѱ�����ʱ�䴰�ڡ� 
		 
		CurrentTime+=WaitTime;					//���µ�ǰʱ�䣻 
								
		Next=DeleteQ(Q);	
		if(CurrentTime>=Next.T)					//1������˿͵��� �� 
			TotalTime+=(CurrentTime-Next.T);	//�ܵȴ�ʱ�� = ��ǰʱ��-�û�����ʱ��  = �û��ȴ�ʱ�� 
			
		if(MaxTime<CurrentTime-Next.T)			//Ѱ�ҳ���ĵȴ�ʱ�� 
				MaxTime=CurrentTime-Next.T;
				 
			
		/*else*/   								//2���˿ͻ�û�е���   ˢ��ÿ�����ڣ�								 
		if(CurrentTime<Next.T){					 
			WaitTime=Next.T-CurrentTime;		//   ˢ��ÿ������ʱ��=   �˿͵���ʱ��-��ǰʱ�䣻
			//ˢ��ÿ�����ڵȴ�ʱ�� 
			for(j=0;j<K;j++){
				Window[j]-=WaitTime;			//���´���   //�����м������  һ������Ϊ0 ��������Ϊ0 ��������Ϊ0 
				if(Window[j]<0)
				Window[j]=0; 			
			}
			
			CurrentTime=Next.T;			   		//3 �ѵ�ǰʱ��������û�����ʱ�伴�� 
		}
		
		for(i=0;i<K;i++)				//��¼���ڴ��������Ҽ�¼�û�����ʱ�� ����ʱ����ѡ����ǵ�һ��Ϊ0���� 
			if(Window[i]==0)
				break;
			temp[i]++; 
			Window[i]=Next.P;			//�ոշ�����Ѵ��ڣ������û�������ʱ�䣻	
		
		if(FinishTime<CurrentTime+Next.P)	//������ʱ��	��ǰʱ��+�˿Ͱ���ʱ��� 
			FinishTime=CurrentTime+Next.P;
			
	}	
	printf("ƽ���ȴ�ʱ�� = %.1f minute(s)\n��ȴ�ʱ�� = %d minute(s)\n������ʱ�� = %d minute(s) \n",(double)TotalTime/(double)N,MaxTime,FinishTime);
	for(i=0;i<K;i++)
		printf("%d\t",temp[i]);
}
void FindNextWindow(int W[],int K,int *waitTime){
	int WinAvail;
	int MinW=MaxProc+1;
	int i;
	for(i=0;i<K;i++)//ɨ��ÿ�����ڣ�Ѱ�ҳ����� ���ʱ�� 
	if(W[i]<MinW){
		MinW=W[i];
//		WinAvail=i;
	}
	*waitTime=MinW;//���ҳ����Ŵ��� 
	
	for(i=0;i<K;i++)//����ÿ������ʱ�� 
	W[i]-=MinW;
		
//	return WinAvail;
}
/*
6
0 20
0 15
0 30
0 2
1 60
3 10
3

5
0 3
0 4
1 2
4 5
5 5
3

9
0 20
1 15
1 60
2 10
10 5
10 3
30 18
31 25
31 2
3

*/
