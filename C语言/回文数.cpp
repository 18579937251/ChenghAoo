#include<stdio.h>
int main(){
	
	int j;
	int num=0;
	for(int i=900;i<=1100;i++){
		int a[4];	// ÿ�� �����ĸ�Ԫ�أ�0-9999��Χ�� 
		j=0;		// λ�� 
		int temp=i;
/*--------------------------------------------------*/	
		while(temp!=0){	//ȡÿһλ��ֵ 
			a[j++]=temp%10;		
			 temp=temp/10;	
		}
//		for(int i=0;i<4;i++){
//			printf("%d",a[i]);
//		}
//		printf("%d",j);
//		printf("a");
		bool Istrue = true;	
		//��Ҫ�������� ż�����ж� 
/*--------------------------------------------------*/		
		if(j%2==1){ 	//���� 
		for(int n=0,temp1=j-1;n!=temp1;n++,temp1--){
			if(a[n]!=a[temp1]){		//˫ָ�� ͷβ��Ƚ�		
				Istrue=false;		//���費������� �������� 
				break;
			}
		}
		if(Istrue){
			printf("%d ",i);	//������;
			num++; 
		}
	}
/*--------------------------------------------------*/	
		else{		//ż������� 	ע���ҵĽ������� 
			for(int n=0,temp1=j-1;n!=temp1+1;n++,temp1--){
			if(a[n]!=a[temp1]){			//˫ָ�� ͷβ��Ƚ�
				Istrue=false;
				break;
			}
		}
		if(Istrue){
			printf("%d ",i);	//������;
			num++; 
		}	
	} 
/*------------------------����------------------------*/	
		if(num==8){
			printf("\n");
			num=0;
		}
			
	} 

	return 0;
} 

