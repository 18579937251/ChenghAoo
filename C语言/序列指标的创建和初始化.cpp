#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
/*------------------------------------------------------------*/
//{ 	//һά���� ��̬�����ڴ�  ��ʼ��
// 
///* 	 
//  calloc malloc ���Ǹ� ��ָ�� �����ڴ� ����calloc Ĭ�ϻὫֵ ��Ϊ 0     
//*/		 
//	int Len=6;
//	int *array=(int *)malloc(sizeof(int)*Len);
//	memset(array,0,sizeof(int)*Len);
///*int *array=(int *)calloc(Len,sizeof(int));*/	
//	for(int i=0;i<Len;i++){
//		printf("%d ",array[i]);
//	} 
//} 
/*------------------------------------------------------------*/
//printf("\n");
//{
//	//��ά����  ��̬�����ڴ� ��ʼ�� 
//	int Len=6;		
//	int **Array=(int**)malloc(sizeof(int*)*Len);		
//	for(int i=0;i<Len;i++){	
//		Array[i]=(int*)calloc(Len,sizeof(int)); 
//	}
//	for(int i=0;i<Len;i++){
//		for(int j=0;j<Len;j++){
//			printf("%d ",Array[i][j]);
//		}
//		printf("\n");
//	}
//	
//}


	int Len=6;
	int *a=(int *)malloc(sizeof(int)*Len);
	memset(a,0,sizeof(int)*Len);

	int *b=(int *)realloc(a,sizeof(int)*(Len/2)); //������a  Len /2;	
	printf("\n*a�׵�ַ%d *b�׵�ַ%d",a,b);
	
	
	












 







	
	return 0;
}

 
