#include<stdio.h>
#include<stdlib.h>
int cmp(const void* a,const void* b){
	return *(const int *)a-*(const int *)b;
}
int main(){
	int N;
	scanf("%d",&N);
	int a[N];
	int Sum=0;
	for(int i=0;i<N;i++){
		scanf("%d",&a[i]);	//�ۼӺ� 
		Sum+=a[i];	
	}
	qsort(a,N,sizeof(int),cmp);	//�������� 
int Pos=Sum;
int S2;							
bool Pos_1=false;
	for(int i=N-1;i>=0;i--){    // i = N-1 �±� 4 3 2 1 0  
		for(int j=0;j<=i;j++){	// j <= i�±�   0 1 2 3 4  
			S2=Pos-a[j];        // Pos ��ʼֵ Sum
//			printf("%d\n",S2);  
			if(Sum-2*S2>=0){		//  �ҵ�"��һ��Ϊ����"�����	
				Pos_1 = true;
				break;
			}								
		}
		if(Pos_1==true){
			break;
		}
		Pos=Pos-a[i];		//���� 1 2 3 4 | 5				
}	
printf("Sum=%d\nS1=%d\nS2=%d\nMin (S1*S1-S2*S2)=%d",Sum,Sum-S2,S2,Sum*(Sum-2*S2));
	return 0;
} 
