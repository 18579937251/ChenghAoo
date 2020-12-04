/*������0.2 vel �汾 ��������Ϸ��ʾ�ȹ��ܣ��Ż���һ�½��棬  ����ͨ�����вʵ�Ӵ���� by ��*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include<windows.h>
#include<time.h>
#include<string.h>
#define caslength 6 

void Initialize();		//��ͼ��ʼ�������ز��� 
void drawMap();			//��ͼ 
void keyDown();			//�������� 
int gameOver();			//��Ϸ�����ж� 
void gameend();			//�˳���Ϸ 
void start();			//��ʼ��Ϸ 
void Nextcas();			//��һ�� 
void Lastcas();			//��һ�� 
void Endgame();			//ͨ����Ϸ���� 
void to_withdraw();		//��Ϸ��ʾ 

int line=10;
int high=10;
int map1[caslength][10][10];//��ʱ���鱣�� 
int cas = 1;	//Ϊ0��ʾ��һ��
int step_number=0;
//��¼ÿһ�ص������� ��������Ŀ��Ŀ����һ�������
int boxSum[caslength] = {4,3,2,3,3,3};

char gamekey[caslength][120]={
"ssswwwaadwwsddd",
"dddwwssaaawwddaassaaww",
"dwwaaawasddddssawdwaaassaaawwddsdsawwwdss",
"assdwssdsdssaawwwawwddssasssddwwawwwaswdwwass",
"wawsdddwwaasasdwaaasddwdwwasdsassdwawwdddssadwwaaassaawd",
"dwwwaaassaawwdassddwwddsdwwwasdsaaassaawwddddsdwsssawwdwawwdssswaaassaawwddddsdwaaaaawwddswaassddddsssdw"
};
//�Լ�������ƹؿ� 10*10 Ŀǰֻ��6�� 
int map[caslength][10][10]={
	{
	0, 0, 1, 1, 1, 0, 0, 0, 0, 0,
	0, 0, 1, 3, 1, 0, 0, 0, 0, 0,	
	0, 0, 1, 0, 1, 1, 1, 1, 1, 0,
	1, 1, 1, 4, 0, 0, 4, 3, 1, 0,
	1, 3, 0, 4, 5, 1, 1, 1, 1, 0,
	1, 1, 1, 1, 0, 1, 0, 0, 0, 0,
	0, 0, 0, 1, 0, 1, 0, 0, 0, 0,
	0, 0, 0, 1, 4, 1, 0, 0, 0, 0,
	0, 0, 0, 1, 3, 1, 0, 0, 0, 0,
	0, 0, 0, 1, 1, 1, 0, 0, 0, 0
	}
,
	{
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,	
	1, 1, 1, 1, 1, 1, 1, 1, 0, 0,
	1, 0, 0, 0, 0, 0, 0, 1, 0, 0,
	1, 3, 1, 0, 1, 1, 3, 1, 0, 0,
	1, 4, 0, 0, 4, 0, 3, 1, 0, 0,
	1, 0, 1, 0, 1, 1, 4, 1, 0, 0,
	1, 0, 0, 5, 0, 0, 0, 1, 0, 0,
	1, 1, 1, 1, 1, 1, 1, 1, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0
	}
,
	{
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,	
	0, 0, 0, 1, 1, 1, 1, 0, 0, 0,
	0, 1, 1, 1, 0, 0, 1, 1, 1, 1,
	0, 1, 0, 0, 0, 0, 0, 4, 0, 1,
	0, 1, 0, 1, 0, 0, 1, 4, 0, 1,
	0, 1, 0, 3, 0, 3, 1, 5, 0, 1,
	0, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0
	}
, 
	{
	0, 1, 1, 1, 1, 0, 0, 0, 0, 0,
	1, 1, 0, 0, 1, 0, 0, 0, 0, 0,	
	1, 0, 5, 0, 1, 0, 0, 0, 0, 0,
	1, 0, 4, 0, 1, 0, 0, 0, 0, 0,
	1, 0, 7, 0, 1, 0, 0, 0, 0, 0,
	1, 0, 7, 0, 1, 1, 0, 0, 0, 0,
	1, 1, 3, 0, 0, 1, 0, 0, 0, 0,
	0, 1, 0, 1, 0, 1, 0, 0, 0, 0,
	0, 1, 0, 0, 0, 1, 0, 0, 0, 0,
	0, 1, 1, 1, 1, 1, 0, 0, 0, 0
	}
,	{
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,	
	0, 0, 1, 1, 1, 1, 0, 0, 0, 0,
	0, 0, 1, 0, 0, 1, 1, 1, 0, 0,
	1, 1, 1, 0, 0, 0, 0, 1, 0, 0,
	1, 0, 0, 7, 3, 1, 0, 1, 0, 0,
	1, 0, 0, 4, 7, 0, 0, 1, 0, 0,
	1, 1, 1, 0, 5, 1, 1, 1, 0, 0,
	0, 0, 1, 0, 0, 1, 0, 0, 0, 0,
	0, 0, 1, 1, 1, 1, 0, 0, 0, 0	
	}
,	{
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 1, 1, 1, 1, 1, 1, 1, 1, 0,	
	0, 1, 0, 0, 0, 1, 0, 0, 1, 0,
	0, 1, 0, 1, 0, 1, 4, 3, 1, 0,
	0, 1, 0, 0, 0, 0, 4, 3, 1, 0,
	0, 1, 0, 1, 0, 1, 4, 3, 1, 0,
	0, 1, 0, 0, 0, 1, 0, 0, 1, 0,
	0, 1, 1, 1, 1, 1, 5, 0, 1, 0,
	0, 0, 0, 0, 0, 1, 1, 1, 1, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0	
	}
};
int map2[1][10][10]={
	{
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 1, 0, 0, 1, 0, 0, 0,	
	0, 0, 1, 0, 1, 1, 0, 1, 0, 0,
	0, 1, 0, 0, 0, 0, 0, 0, 1, 0,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	0, 1, 0, 0, 0, 0, 0, 0, 1, 0,
	0, 0, 1, 0, 0, 0, 0, 1, 0, 0,
	0, 0, 0, 1, 0, 0, 1, 0, 0, 0,
	0, 0, 0, 0, 1, 1, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0			
	}
};
int main()
{	int startTime,endTime,toileTime=0; 
	start();
	Initialize();
	system("color 8E");
	while (1)
	{
		startTime=clock();
		
		printf("\n\n\t\t   �ڡ�%d���� ���Ѿ�����%d��\t��Ϸ����ʱ��%d ��\n\t\t\t\t\t\t ������ ��Ŀ�ĵ� ����\n \t\t\t\t\t\tR:����  T:��һ��  Y:��һ��  X:��Ϸ��ʾ  U:�˳���Ϸ \n",cas,step_number,120-toileTime/1000);
//		if(60-toileTime/1000==0)
//		exit(0); 
		drawMap();
		if (gameOver() == boxSum[cas])
		{
			cas++;
			Initialize();
			if (cas >=caslength){
				system("cls");
				Endgame();
				break;
			}
		}
		keyDown();
		
		endTime=clock();
		
		toileTime=toileTime+(endTime-startTime);
		
		system("cls");
	}
//	printf("\t\t\t\t��ϲ��ͨ����Ϸ������������\n\n");
	system("pause");
	return 0;
}

void Initialize(){
	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j < high; j++)
		{
		map1[cas][i][j]=map[cas][i][j];
		}
	}
	step_number=0; 
}
void drawMap()
{
	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j < high; j++)
		{
			if (j == 0)
				printf("\t\t");
			switch (map1[cas][i][j])
			{
		
			case 0:
				printf("  ");
				break;
			case 1:
				printf("��");
				break;

			case 3:
				printf("��");
				break;
			case 4:
				printf("��");
				break;

			case 5:
			case 8:
				printf("��"); 
				break;
			case 7:
				printf("��");
				break;
	
			}
		}
		printf("\n");
	}
}
//��������
void keyDown()
{
	//������������
	//��λ��������
	//���������������һ���ǣ��ˣ��ڶ�������վ��Ŀ����
	int i, j;
	for (i = 0; i < line; i++)
	{
		for (j = 0; j < high; j++)
		{
			if (map1[cas][i][j] == 5 || map1[cas][i][j] == 8)
			{
				break;
			}
		}
		if (map1[cas][i][j] == 5 || map1[cas][i][j] == 8)
		{
			break;
		}
	}
 
	char ch = _getch();	//���������ַ����룬+ͷ�ļ� conio.h
	switch (ch)
	{
		//72 80   75 77
	case 'w':
	case 'W':
	case 72:
		//��һ���ط����ڿյػ�����Ŀ�� ����
		if (map1[cas][i - 1][j] == 0 || map1[cas][i - 1][j] == 3)
		{
			//3+5=8 ����ʾĿ�ĺ�����һ��
			//�µط�(map[i-1][j])�ˣ�5������
			map1[cas][i - 1][j] += 5;
			//�ϵط�(map[i][j])�ˣ�5������
			map1[cas][i][j] -= 5;
			step_number++;
		}
		//�����һ�������ӣ�Ҫ��һ���ж�����
		//ע��㣺��������״̬�����ӣ����Ӻ�Ŀ����һ��
		else if (map1[cas][i - 1][j] == 4 || map1[cas][i - 1][j] == 7)
		{
			//�����ӵ���һ���ط��ж��ܲ�����
			if (map1[cas][i - 2][j] == 0 || map1[cas][i - 2][j] == 3)
			{
				//�µĵط���������
				map1[cas][i - 2][j] += 4;
				//���ӵ�λ�ã����ӣ�-4������ ������+5��
				map1[cas][i - 1][j] += 1;
				//ԭ���ĵط�������
				map1[cas][i][j] -= 5;
				step_number++;
			}
 
		}
 
		break;
	case 's':
	case 'S':
	case 80:
		//��һ���ط����ڿյػ�����Ŀ�� ����
		if (map1[cas][i + 1][j] == 0 || map1[cas][i + 1][j] == 3)
		{
			//3+5=8 ����ʾĿ�ĺ�����һ��
			//�µط�(map[i-1][j])�ˣ�5������
			map1[cas][i + 1][j] += 5;
			//�ϵط�(map[i][j])�ˣ�5������
			map1[cas][i][j] -= 5;
			step_number++;
		}
		else if (map1[cas][i + 1][j] == 4 || map1[cas][i + 1][j] == 7)
		{
			//�����ӵ���һ���ط��ж��ܲ�����
			if (map1[cas][i + 2][j] == 0 || map1[cas][i + 2][j] == 3)
			{
				//�µĵط���������
				map1[cas][i + 2][j] += 4;
				//���ӵ�λ�ã����ӣ�-4������ ������+5��
				map1[cas][i + 1][j] += 1;
				//ԭ���ĵط�������
				map1[cas][i][j] -= 5;
				step_number++;
			}
 
		}
		break;
 
	case 'a':
	case 'A':
	case 75:
		//��һ���ط����ڿյػ�����Ŀ�� ����
		if (map1[cas][i][j - 1] == 0 || map1[cas][i][j - 1] == 3)
		{
			//3+5=8 ����ʾĿ�ĺ�����һ��
			//�µط�(map[i-1][j])�ˣ�5������
			map1[cas][i][j - 1] = map1[cas][i][j - 1] + 5;
			//�ϵط�(map[i][j])�ˣ�5������
			map1[cas][i][j] = map1[cas][i][j] - 5;
			//j+=5  j=j+5
 			step_number++;
		}
		else if (map1[cas][i][j - 1] == 4 || map1[cas][i][j - 1] == 7)
		{
			//�����ӵ���һ���ط��ж��ܲ�����
			if (map1[cas][i][j - 2] == 0 || map1[cas][i][j - 2] == 3)
			{
				//�µĵط���������
				map1[cas][i][j - 2] += 4;
				//���ӵ�λ�ã����ӣ�-4������ ������+5��
				map1[cas][i][j - 1] += 1;
				//ԭ���ĵط�������
				map1[cas][i][j] -= 5;
				step_number++;
			}
 
		}
 
		break;
	case 'D':
	case 'd':
	case 77:
		//��һ���ط����ڿյػ�����Ŀ�� ����
		if (map1[cas][i][j + 1] == 0 || map1[cas][i][j + 1] == 3)
		{
			//3+5=8 ����ʾĿ�ĺ�����һ��
			//�µط�(map[i-1][j])�ˣ�5������
			map1[cas][i][j + 1] += 5;
			//�ϵط�(map[i][j])�ˣ�5������
			map1[cas][i][j] -= 5;
			step_number++;	//����++ 
		}
		
		//��һ���ط������ӣ��ж����ӵ���һ���ط��ǲ���Ŀ�ĺͿյ�
		else if (map1[cas][i][j + 1] == 4 || map1[cas][i][j + 1] == 7)
		{
			//�����ӵ���һ���ط��ж��ܲ�����
			if (map1[cas][i][j + 2] == 0 || map1[cas][i][j + 2] == 3)
			{
				//�µĵط���������
				map1[cas][i][j + 2] += 4;
				//���ӵ�λ�ã����ӣ�-4������ ������+5��
				map1[cas][i][j + 1] += 1;
				//ԭ���ĵط�������
				map1[cas][i][j] -= 5;
				step_number++;
			}
 
		}			
		break;
	case 'R':
	case 'r':
		Initialize();
		break;
	case 'u':
	case 'U':
		gameend();
		break;
	case 't':
	case 'T':
		Nextcas();
		break;
	case 'y':
	case 'Y':
		Lastcas();
		break;
	case 'x':
	case 'X':
		to_withdraw();
		break;	
	}
}
//ʤ���ж�
//��ʲô�ж�ʤ���� ���ӵ���Ŀ�ĵĸ���
int gameOver()
{
	int count = 0;
	//���еĵط���һ��
	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j < high; j++)
		{
			if (map1[cas][i][j] == 7)
				count++;
		}
	}
	return count;
}
void gameend(){
	printf("�˳���Ϸ�ɹ�........"); 
	exit(0);
}
void start(){
	int i=0;
	printf("\n\n\n\n\n\n\n\n\t\t\t\t\t������0.2 ver by:�� ");
	Sleep(2000);
	system("cls");
	char str[]="654321";
	while(str[i++]!='\0'){
		printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t��Ϸ��ʼ����ʱ:%c",str[i]);
		Sleep(520);
		system("cls");
	}
}
void Nextcas(){
	if(cas+1<caslength)
		cas++;
	Initialize();	
}
void Lastcas(){
	if(cas-1>=0)
		cas--;
	Initialize();
}
void Endgame(){
	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j < high; j++)
		{
			if (j == 0)
				printf("\t\t\t\t");
			switch (map2[0][i][j])
			{
		
			case 0:
				Sleep(66);
				printf("  ");
				break;
			case 1:
				Sleep(66);
				printf("��");
				break;
			}
		}
		printf("\n");
	}
	printf("��ϲ��ͨ������Ϸ~\n\n\n\n\n\n\n\n\n\n"); 
}
void to_withdraw(){
	int n=0;
	Initialize();
	while(gamekey[cas][n]!='\0'){
		drawMap();
		int i, j;
	for (i = 0; i < line; i++)
	{
		for (j = 0; j < high; j++)
		{
			if (map1[cas][i][j] == 5 || map1[cas][i][j] == 8)
			{
				break;
			}
		}
		if (map1[cas][i][j] == 5 || map1[cas][i][j] == 8)
		{
			break;
		}
	}
	char ch=gamekey[cas][n++];
	Sleep(200); 
	switch (ch)
	{
	case 'w':
	case 'W':
	case 72:
		if (map1[cas][i - 1][j] == 0 || map1[cas][i - 1][j] == 3)
		{
			map1[cas][i - 1][j] += 5;
			map1[cas][i][j] -= 5;
			step_number++;
		}
		else if (map1[cas][i - 1][j] == 4 || map1[cas][i - 1][j] == 7)
		{
			if (map1[cas][i - 2][j] == 0 || map1[cas][i - 2][j] == 3)
			{
				map1[cas][i - 2][j] += 4;
				map1[cas][i - 1][j] += 1;
				map1[cas][i][j] -= 5;
			}
 
		}
 
		break;
	case 's':
	case 'S':
	case 80:
		if (map1[cas][i + 1][j] == 0 || map1[cas][i + 1][j] == 3)
		{
			map1[cas][i + 1][j] += 5;
			map1[cas][i][j] -= 5;
		}
		else if (map1[cas][i + 1][j] == 4 || map1[cas][i + 1][j] == 7)
		{
			if (map1[cas][i + 2][j] == 0 || map1[cas][i + 2][j] == 3)
			{
				map1[cas][i + 2][j] += 4;
				map1[cas][i + 1][j] += 1;
				map1[cas][i][j] -= 5;
			}
 
		}
		break;
 
	case 'a':
	case 'A':
	case 75:
		if (map1[cas][i][j - 1] == 0 || map1[cas][i][j - 1] == 3)
		{
			map1[cas][i][j - 1] = map1[cas][i][j - 1] + 5;
			map1[cas][i][j] = map1[cas][i][j] - 5;
 			step_number++;
		}
		else if (map1[cas][i][j - 1] == 4 || map1[cas][i][j - 1] == 7)
		{
			if (map1[cas][i][j - 2] == 0 || map1[cas][i][j - 2] == 3)
			{
				map1[cas][i][j - 2] += 4;
				map1[cas][i][j - 1] += 1;
				map1[cas][i][j] -= 5;
			}
 
		}
 
		break;
	case 'D':
	case 'd':
	case 77:
		if (map1[cas][i][j + 1] == 0 || map1[cas][i][j + 1] == 3)
		{
			map1[cas][i][j + 1] += 5;
			map1[cas][i][j] -= 5;
		}
		else if (map1[cas][i][j + 1] == 4 || map1[cas][i][j + 1] == 7)
		{
			if (map1[cas][i][j + 2] == 0 || map1[cas][i][j + 2] == 3)
			{
				map1[cas][i][j + 2] += 4;
				map1[cas][i][j + 1] += 1;
				map1[cas][i][j] -= 5;
			}
		}			
		break;		
	}
	system("cls");
	}
	Initialize();
}
