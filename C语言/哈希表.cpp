#include<stdio.h>
#include<string.h>
struct Entry{
	char data;	// valueֵ 
	int count;	// ���ֵĴ��� 
};
void addOne(struct Entry *CountMap,char Num,int HashTableSize);			//Add Num
void FindHand(struct Entry *CountMap,char Value,int HashTableSize); 		//Find Num 
int Collision_Count=0; 	//��ײ ���� 
int main(){

	int HashTableSize = 10;    				//������10����λ�� 	��Ȼ������Ը���ʵ������޸� 
	struct Entry CountMap[HashTableSize];   //Map 
	for(int i=0;i<HashTableSize;i++){
		CountMap[i].count=0;				//20��λ�� ��ʼ��������Ϊ 0
		CountMap[i].data =NULL;	
	}
	char a[]="gaogaotwo"; 					

	for(int i=0;i<strlen(a);i++){	
		addOne(CountMap,a[i],HashTableSize);	
	}
	
	for(int i=0;i<HashTableSize;i++){	//printf  
		printf("Data:%c Count:%d \n",CountMap[i].data,CountMap[i].count);
	}
	
	FindHand(CountMap,'o',HashTableSize);
//	printf("��ײ����:%d",Collision_Count); 
	return 0;
}
void addOne(struct Entry *CountMap,char Num,int HashTableSize){	// �������� ��һ�� Map�ֵ�  �ڶ��� valueֵ  ������HashSize��С 

	int Hash = (Num % HashTableSize + HashTableSize) % HashTableSize;  // Key % 
	while(true){				  //�ܹ��� 3�ֿ����� 					����Ѱַ��
		if(CountMap[Hash].count==0){ 	//��һ��     ��ʾ��ʱ���λ��"û��Ԫ��" ֱ�ӷ��� 	
		   CountMap[Hash].data = Num;	// ��ֵ 
		   CountMap[Hash].count = 1;	//����Ϊ 1    
		   return;
		}								//�ڶ���    ��ʾ��λ����Ԫ�� ��Ԫ��ֵ������ 
		if(CountMap[Hash].data==Num){
		   CountMap[Hash].count++;		//  Ԫ�س��ִ��� + 1
		   return; 
		}
										//������ ������Ǹ�λ���ѱ�ռ��(��ͻ��)����Ԫ��ֵ����ȣ��ͼ�����ѯ��һ��λ��һֱ���ҵ�Ϊ׼  
		Hash=(Hash+1)%HashTableSize;    //���� ̽��  
//		Collision_Count++;				//������ײ����    
	} 
}
void FindHand(struct Entry *CountMap,char Value,int HashTableSize){

	int Hash = (Value % HashTableSize + HashTableSize) % HashTableSize;	 //Key
	
	
	if(CountMap[Hash].data==Value){					//�Ƿ� ��û�з�����ͻ���� 
		printf("id:%d ��ѯ�ɹ�\n",Hash);
		return;
	}
	
	int temp = Hash+1;
	
	while(temp!=Hash){
		if(CountMap[temp].data==Value){
		printf("id:%d %d ��ѯ�ɹ�\n",temp,Value);
		return;
		}
		temp=(temp+1)%HashTableSize;													
	}
	printf("��ѯʧ��\n");
	return;
} 
