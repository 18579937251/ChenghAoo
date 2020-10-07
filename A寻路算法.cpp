#include<stdio.h>
#include<vector>
#include<stdlib.h>
#include <memory.h> 
#include<windows.h>
using namespace std;
#define ROW 10
#define COLS 10
#define linear_cost 10	//ֱ�ߴ��� 
#define slash_cost 14	//б�ߴ��� 
struct Mypoint{
	int Row;
	int Cols;
	int F;	 
	int G;	 // ����Χ�ڵ���� 
	int H;	 // �յ㵽��ǰ�ڵ���� 
	void f(){
		F=G+H;
	}
};

struct TreeNode{
	Mypoint Pos;				//���� 
	TreeNode* Parents; 			//���׽ڵ� 
};

enum direct{_up,_down,_left,_right,up_l,up_r,down_l,down_r};	//ö�� ���� 
void DrawMap(int drawMap[ROW][COLS],TreeNode* LNode);			//��ͼ 
int GetH(Mypoint endPos,Mypoint Pos);							//��ȡ H ����ֵ  
bool NeeAdd(Mypoint Pos,int MAP[ROW][COLS],bool Auxiliary_Maps[ROW][COLS]);	//�ж� ��ǰ�ڵ��Ƿ������� 
TreeNode* A_Algorithms(int Map[ROW][COLS],bool Auxiliary_Maps[ROW][COLS],Mypoint BeginPos,Mypoint EndPos);	//A* 
 
int main(){

			Mypoint BeginPos={1,1};				 
			Mypoint EndPos={1,8};
			
		int MAP[ROW][COLS]={
			{1,1,1,1,1,1,1,1,1,1},
			{1,0,0,0,0,0,0,0,0,1},
			{1,0,0,0,0,0,0,0,0,1},
			{1,0,0,0,0,0,0,0,0,1},
			{1,0,0,0,0,0,0,0,0,1},
			{1,0,0,0,0,0,0,0,0,1},
			{1,0,0,0,0,0,0,0,0,1},
			{1,0,0,0,0,0,0,0,0,1},
			{1,0,0,0,0,0,0,0,0,1},
			{1,1,1,1,1,1,1,1,1,1},
		};
				
		bool Auxiliary_Maps[ROW][COLS]={0};			//��¼�Ƿ��߹�						
		Auxiliary_Maps[BeginPos.Row][BeginPos.Cols]=true;	
		TreeNode *Start=A_Algorithms(MAP,Auxiliary_Maps,BeginPos,EndPos);
		if(Start)		 	
			DrawMap(MAP,Start);
		
		free(Start);								//�ͷ�Start	
	return 0;
}
void DrawMap(int drawMap[ROW][COLS],TreeNode* LNode){
	
	while(LNode){
		
		drawMap[LNode->Pos.Row][LNode->Pos.Cols]=2;
		for(int i=0;i<ROW;i++){
		for(int j=0;j<COLS;j++){		
			if(drawMap[i][j]==1)
				printf("#");
			if((i==LNode->Pos.Row&&j==LNode->Pos.Cols)||drawMap[i][j]==2)
				printf("*");
			if(drawMap[i][j]==0)
				printf(" ");
		}
		printf("\n");	
	}			
		LNode=LNode->Parents;
		Sleep(100);
		system("cls");	
}
	for(int i=0;i<ROW;i++){
		for(int j=0;j<COLS;j++){
			if(drawMap[i][j]==0)
				printf(" ");
			if(drawMap[i][j]==1)
				printf("#");
			if(drawMap[i][j]==2)
				printf("*");
		}
		printf("\n");
	}
	
	getchar();getchar();
}
// ����H ֵ���� �յ���� 
int GetH(Mypoint endPos,Mypoint Pos){ 				//���õ��ǹ���������ֱ�ߵ�ǰ�յ㵽�������ֵ 
													//ע����������� 
	int x= endPos.Cols > Pos.Cols ? endPos.Cols - Pos.Cols : Pos.Cols - endPos.Cols;
	int y= endPos.Row > Pos.Row ? endPos.Row - Pos.Row : Pos.Row - endPos.Row;
	return (x+y)*linear_cost;
}
//��ͼ�޶����� 
bool NeeAdd(Mypoint Pos,int MAP[ROW][COLS],bool Auxiliary_Maps[ROW][COLS]){
	if(Pos.Row>=ROW|| Pos.Row<0||Pos.Cols>=COLS|| Pos.Cols<0) 	//��ͼ�߽� 
		return false;
	if(MAP[Pos.Row][Pos.Cols]==1)								//ǽ 
		return false;
	if(Auxiliary_Maps[Pos.Row][Pos.Cols])						//���߹� 
		return false;	
	return true;									 

}
TreeNode* A_Algorithms(int Map[ROW][COLS],bool Auxiliary_Maps[ROW][COLS],Mypoint BeginPos,Mypoint EndPos){
	
		
		TreeNode* Pcurrent= new TreeNode;		//���׽ڵ� 
		memset(Pcurrent ,0, sizeof(TreeNode));		
		Pcurrent->Pos=BeginPos;					//��¼��ʼλ�� 
		
		vector<TreeNode*>Buff;					//װ���ӵ����� 
		TreeNode* pChild = NULL;				//���ӽڵ� 
		
		//������ 
		vector<TreeNode*>::iterator it;
		vector<TreeNode*>::iterator itMin;
		bool IsFind =false;
		while(true){
				
			for(int i=0;i<8;i++){
				// �������� б�������� �ڵ���ۼ��� 
				pChild=new TreeNode;	
				memset(pChild ,0, sizeof(TreeNode));	
				pChild->Pos=Pcurrent->Pos;
				
				switch(i){
					case _up:
						pChild->Pos.Row--;			//����仯 
						pChild->Pos.G+=linear_cost;	
						break;
					case _down:
						pChild->Pos.Row++;
						pChild->Pos.G+=linear_cost;	
						break;
					case _left:
						pChild->Pos.Cols--;
						pChild->Pos.G+=linear_cost;	
						break;
					case _right:
						pChild->Pos.Cols++;
						pChild->Pos.G+=linear_cost;	
						break;
					case up_l:
						pChild->Pos.Row--;
						pChild->Pos.Cols--;
						pChild->Pos.G+=slash_cost;	
						break;
					case up_r:
						pChild->Pos.Row--;
						pChild->Pos.Cols++;
						pChild->Pos.G+=slash_cost;	
						break;
					case down_l:
						pChild->Pos.Row++;
						pChild->Pos.Cols--;
						pChild->Pos.G+=slash_cost;	
						break;
					case down_r:
						pChild->Pos.Row++;
						pChild->Pos.Cols++;
						pChild->Pos.G+=slash_cost;	
						break;		
				}
				//�߽�����ж� ȥ��û�� �߽� �����ϵĽڵ� 
				if(pChild->Pos.Row==-1||pChild->Pos.Row==-1||pChild->Pos.Row==10||pChild->Pos.Row==10){
					delete pChild;
					continue;
				}
				
				//��ȡ H �յ㵽�� ��ǰ�ڵ�Ĵ��� 
				pChild->Pos.H=GetH(EndPos,pChild->Pos);
				pChild->Pos.f();
				
				// ��ѯ�Ƿ���ϵĽڵ� �������ϵĽڵ���������� 	
				if(NeeAdd(pChild->Pos , Map , Auxiliary_Maps)){			
//					Pcurrent->Childs.push_back(pChild);		
					pChild->Parents=Pcurrent;
					
					Buff.push_back(pChild);		// ����һ������ Buff�� 
					Auxiliary_Maps[pChild->Pos.Row][pChild->Pos.Cols]=true; //�߽�ýڵ�λ������ 
				}
				//�����ϵ�  �Ѿ��߹� ���� ˵ �������� ǽ 
				else{	
					delete pChild;
				}
						
			}
		 
		// �ҳ�  Buff �����д���ֵ��С��һ���� 
		itMin=Buff.begin();										//�����һ���ڵ� ������Сֵ 
		for(it=Buff.begin();it!=Buff.end();it++)
			itMin=(*itMin)->Pos.F>(*it)->Pos.F ? it : itMin;	//ѡ����С��
 
			/* ��Ȼ��Ҳ��������д
				if((*itMin)->Pos.F>(*it)->Pos.F)
					itMin=it;		
			*/
			 	
			Pcurrent=*itMin;					// ѡ�����ֵ ��С��һ���ڵ� ��Ϊ��ǰ�ڵ�  
			//delete itMin    		 	
			Buff.erase(itMin);
		// �������� ��ǰ�ڵ� ������ֵ ���� ��ѯ�ڵ� 
		if(Pcurrent->Pos.Row==EndPos.Row&&Pcurrent->Pos.Cols==EndPos.Cols)	
		{
			IsFind = true;
			break;
		}
//		if(Buff.empty()) 
//			break;			
	} 	
		if(IsFind)
			return Pcurrent;
		else{
			printf("��·��");
			return Pcurrent; 
		}	
}	


