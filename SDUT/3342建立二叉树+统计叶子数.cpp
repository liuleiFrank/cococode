#include<stdio.h>
#include<stdlib.h>

typedef struct BiTNode{
	char data;
	struct BiTNode* lc;
	struct BiTNode* rc;
}BiTNode;

void CreateTree(BiTNode * &T,char c[51],int &num)
{
	if (c[num]==',')
		T=NULL;
	else
	{
		BiTNode* S=(BiTNode*)malloc(sizeof(BiTNode));
		S->data=c[num];
		T=S;
		CreateTree(T->lc,c,++num);
		CreateTree(T->rc,c,++num);
	}
}

void Preorder(BiTNode* T)
{
	if(T!=NULL)
	{
		printf("%c",T->data);
		Preorder(T->lc);
		Preorder(T->rc);
	}
}

void Count(BiTNode* T,int &N)
{
	if (T!=NULL)
	{
		if (T->lc==NULL && T->rc==NULL)
			N++;
		else 
		{
			if (T->lc!=NULL)
				Count(T->lc,N);
			if (T->rc!=NULL)
				Count(T->rc,N);
		}
	}

}

int main()
{
	char c[51];
	while(scanf("%s",c)!=EOF)
	{
		int num=0;
		BiTNode* T=NULL;
		CreateTree(T,c,num);
		//Preorder(T);
		int N=0;
		Count(T,N);
		printf("%d\n",N);
	}
	return 0;
}