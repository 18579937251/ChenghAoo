/*
 Leetcode 1
  
������ ���ִ�������һ�� �����������ֶ�����������
#include<stdio.h>
int Repeatable(int *NUM,int length){

	int mun=NUM[0];
		for(int i=1;i<length;i++)
			mun^=NUM[i];	
	return mun;
}
int main(){	
	int num[]={1,1,3,3,2,2,7};	
	printf("%d \n",Repeatable(num,7));
	return 0;
}*/
/*

Leetcode 2 
������ 21  �ػ��Ƿ�Ϊ 1 �Ǿ�λ������ ������Ϊ �������� ����ָ�� 
#include<stdio.h>
int surplus(int Number){

	int Sum=0;
	while(Number!=0){
		int sum1= Number%10;
		Sum+=(sum1*sum1);
		Number=Number/10;
	}
	return Sum;
}
int main(){

	int Pos=21;
	int fast=surplus(surplus(Pos));
	int slow=surplus(Pos);
		
	while(fast!=slow){
		fast=surplus(fast);
		fast=surplus(fast);
		slow=surplus(slow);
	}	
	if(fast==1){
		printf("%d ������\n",Pos);
	}
	else
		printf("%d ���ǿ�����\n",Pos);
	return 0;
}
*/
/*
Leetcode 3

һ�������������е����ֵ �����ж� ע��ȥ�� 
#include<stdio.h>
#define INT_MIN -2147483648 
int Maxadjective(int *adjective,int length){

	int MaxSIZE = INT_MIN;
	
	for(int i=0;i<length;i++){
		int sum=0;
		for(int j=i;j<length;j++){
			sum+=adjective[j];
			if(sum>MaxSIZE)
				MaxSIZE=sum;				
		}
	}
	return MaxSIZE;
}
int main(){

	int Num[]={1,2,-1,-5,-1,1,2,3,4,-7};
	printf("Max=%d",Maxadjective(Num,10));
	return 0;
} 
*/ 
/*
 Leetcode 15
		intput
		[1,2,3,4] 
		output
		[24,12,8,6]
		Leetcode 14



#include<stdio.h>
#include<stdlib.h>

int *Sequences(int *Num,int NumSize,int *ReturnSize){
	
	int* Result = (int*)malloc(sizeof(int)*NumSize);
	
	for(int i=0;i<NumSize;i++){
		Result[i]=1;		//ע�⸽��ֵ 
		for(int j=0;j<NumSize;j++)
			if(i!=j)
				Result[i]*=Num[j];	
	}
	return Result;
}
int main(){

	int a[100]={1,2,3,4};
	int *Num=Sequences(a,4,Num);
	
	for(int i=0;i<4;i++)
		printf("%d ",Num[i]);
	return 0;
}
*/
/* 
//LeetCode �ظ����� ȥ���ظ������� 
#include<stdio.h>
#include<stdlib.h>
int FibonacciSeries(int* Investigate,int Size){
	
	if(Investigate[Size]!=0)
		return Investigate[Size];
	if(Size==0||Size==1){
		Investigate[Size]=1;	
		return 1;
	}
	else{
		Investigate[Size]=FibonacciSeries(Investigate,Size-1)+FibonacciSeries(Investigate,Size-2);
	}
		return FibonacciSeries(Investigate,Size-1)+FibonacciSeries(Investigate,Size-2);
	
}
int main(){

	int* Investigate=(int*)malloc(sizeof(int)*30);
	for(int i=0;i<30;i++)
		Investigate[i]=0;
	for(int i=0;i<30;i++)
		printf("%d \n",FibonacciSeries(Investigate,i));	
	return 0;
}
*/
/* ��άָ������ڴ�
#include<stdio.h>
#include<stdlib.h>
int main(){

	int** a=(int**)malloc(sizeof(int*)*5);
	for(int i=0;i<5;i++)
		a[i]=(int*)calloc(5,sizeof(int));	
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++)
			printf("%d ",a[i][j]);
			printf("\n");
	}

	return 0;
}*/
/*Leetcode 

qsort char ����

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmp(const void* a,const void* b){
	
	return *(const char*)a-*(const char*)b;
}
//int cmp(const char* a,const char* b){	
//	return *a-*b;
//}
int main(){

	char a[]="abcdadadasdga";
	char b[]="sadasfahiquwhruikbg";
	qsort(a,strlen(a),sizeof(char),cmp);
	qsort(b,strlen(b),sizeof(char),cmp);
	printf("%s\n%s",a,b);
	return 0;
}
*/
/*���� int
#include<stdio.h>
#include<stdlib.h>
int cmp(const void* a,const void* b){
	return *(const int *)a-*(const int *)b;
}
int main(){

	int a[]={3,2,1,3,4,5,6,2,3,5};
	int b[]={4,5,6,2,4,5,6,1,2,5};
	
	qsort(a,10,sizeof(int),cmp);
	qsort(b,10,sizeof(int),cmp);
	for(int i=0;i<10;i++)
		printf("%d %d\n",a[i],b[i]);
	return 0;
}
*/

/*
��̬��� �����ַ����仯 ������С 

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int Min3(int a,int b,int c);
int String_variations(char *a1,char *a2,int len1,int len2,int **case1);
int main(){

	char a[]="a";
	char b[]="a";
	
	int **case1=(int**)malloc(sizeof(int*)*strlen(a)+1);
	
	for(int i=0;i<=strlen(a);i++){
		case1[i]=(int*)malloc(sizeof(int)*strlen(b)+1);
	}
	for(int i=0;i<=strlen(a);i++){
		for(int j=0;j<=strlen(b);j++){
			case1[i][j]=-1;
		}	
	}
	
	printf("��С��Ҫ�仯�Ĵ���Ϊ :%d ",String_variations(a,b,strlen(a),strlen(b),case1));
	
	return 0;
} 
int Min3(int a,int b,int c){
	return a>b?a>c?:a:b>c?b:c;
}
int String_variations(char *a1,char *a2,int len1,int len2,int **case1){
	//
//	case 1 ��ȵ�����²��� 
	
//	case 2 ����
	
//	case 3 ɾ��
	
//	case 4 �޸�  
	
	
	if(len1==0){
		case1[len1][len2]=len2;
		return len2; 
	}
	if(len2==0){	
		case1[len1][len2]=len1;
		return len1; 
	}
	//�ظ������ 
	if(case1[len1-1][len2-1]!=-1)
		return case1[len1-1][len2-1];
		
		
	if(a1[len1-1]==a2[len2-1]){
		return String_variations(a1,a2,len1-1,len2-1,case1);
	}
	case1[len1-1][len2-1]=Min3(
	String_variations(a1,a2,len1,len2-1,case1),
	String_variations(a1,a2,len1-1,len2,case1),
	String_variations(a1,a2,len1-1,len2-1,case1)	
	)+1;
	
} 
*/










 
