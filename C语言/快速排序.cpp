/*Leetcode 

qsort char ����
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int *PosCount;
int cmp(const void* a,const void* b){
	int deff = PosCount[*(const char*)b]-PosCount[*(const char*)a];
		if(deff==0)
			return *(const char*)a-*(const char*)b;		
	return deff;								//������� 
}
//int cmp(const char* a,const char* b){	
//	return *a-*b;
//}
int main(){

	char a[]="abcdadadasdga";
	char b[]="sadasfahiquwhruikbg";
	int Count[128]={0};	
	for(int i=0;i<strlen(a);i++){	//��¼�ַ������ִ��� 
		Count[b[i]]++;	
	}
	PosCount=Count;
//	qsort(a,strlen(a),sizeof(char),cmp);
	qsort(b,strlen(b),sizeof(char),cmp);
	printf("%s\n%s",a,b);
	return 0;
}
*/




/*���� int
#include<stdio.h>
#include<stdlib.h>	// ������ ���� ���� qsort() 
int cmp(const void* a,const void* b){				//�ȽϺ��� 
													// *a ���� *b ǰ�� ����һ������  ���ڴ�С�������� 
	return *(const int *)a-*(const int *)b;			// *a  ��  *b ��� ����ֵΪ 0													 
}													// *b ���� *a ǰ�� ����һ������  ���ڴӴ�С����  
int main(){
	
	int a[]={3,2,1,3,4,5,6,2,3,5};	
	qsort(a,10,sizeof(int),cmp);	//qsort 4������ ��һ�� ����Ԫ������ �׵�ַ 	
	for(int i=0;i<10;i++){			//           	�ڶ��� ����Ԫ��Ԫ�� ���� 
		printf("%d ",a[i]); 		//              ������ ����Ԫ�� ռ�ÿռ��С �������ַ� ����... int char float double struct 
	}								//              ���ĸ� int ���ͱȽϺ���  �������ñȽϺ�������ʽ  
	return 0;
}
*/
/*
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int *PosCount;
int cmp(const void* a,const void* b){
	int deff = PosCount[*(const char*)b]-PosCount[*(const char*)a];
		if(deff==0)
			return *(const char*)a-*(const char*)b;		
	return deff;								//������� 
}
//int cmp(const char* a,const char* b){	
//	return *a-*b;
//}
int main(){

	char a[]="abcdadadasdga";
	char b[]="sadasfahiquwhruikbg";
	int Count[128]={0};	
	for(int i=0;i<strlen(a);i++){	//��¼�ַ������ִ��� 
		Count[b[i]]++;	
	}
	PosCount=Count;
//	qsort(a,strlen(a),sizeof(char),cmp);
	qsort(b,strlen(b),sizeof(char),cmp);
	printf("%s\n%s",a,b);
	return 0;
}
*/




#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmp(const void* a,const void* b){
	
	return *(const char*)a-*(const char*)b;		// �ַ�����  ��С��������  
}

int main(){
	char a[]="gaogaotwo";
	qsort(a,strlen(a),sizeof(char),cmp);
	printf("%s",a);
	return 0;
}






67



