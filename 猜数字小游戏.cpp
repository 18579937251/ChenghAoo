#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	srand( (unsigned int)time(0));//��ʼ������Ϊ���ֵ
	int i=0;
	int guess;
	int num = rand() % 10;//����һһ��0-9֮�����

for(;i <3;++i)
    {
    	printf("������һ������,�㻹��%d�λ���:\n",3-i);
         scanf("%d",&guess);
         if(guess>num)
         {
             printf("���˴���\n");
         }
         if(guess<num)
         {
             printf("С��С��\n");
         }
         if(guess==num)
         {
             printf("��ϲ��¶��ˣ�\n");
             break;				//����˵��ǰ������������ȷ�� Ҫ����for 
         }
    }
    printf("%d",i); 
    if(i==3&&guess!=num)		//�ж��������� ����˵3�ζ��´��ˣ����Ҵ�ʱ i==3 !! ������ 4  
    {
        printf("\n��̫����Ӵ");
    }
 return 0;
}
