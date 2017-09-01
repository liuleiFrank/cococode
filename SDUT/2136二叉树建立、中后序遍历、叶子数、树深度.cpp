#include<stdio.h>
#include<stdlib.h>

typedef struct BiTNode{
	char data;
	struct BiTNode* lc;
	struct BiTNode* rc;
}BiTNode;

void CreateTree(BiTNode* &T,char str[],int &n)
{
	if (str[n]!=',')
	{
		BiTNode* S=(BiTNode*)malloc (sizeof(BiTNode));
		S->data=str[n];
		T=S;
		CreateTree(T->lc,str,++n);
		CreateTree(T->rc,str,++n);
	}
	else
		T=NULL;
}

void InOrder(BiTNode* T)
{
	if (T!=NULL)
	{
		InOrder(T->lc);
		printf("%c",T->data);
		InOrder(T->rc);
	}
}

void PostOrder(BiTNode* T)
{
	if (T!=NULL)
	{
		PostOrder(T->lc);
		PostOrder(T->rc);
		printf("%c",T->data);
	}
}

void CountLeaf(BiTNode* T,int &numleaf)
{
	if (T!=NULL)
	{
		if (T->lc==NULL && T->rc==NULL)
			numleaf++;
		else
		{
			CountLeaf(T->lc,numleaf);
			CountLeaf(T->rc,numleaf);
		}
	}
}

int getdepth(BiTNode* T)
{
	if (T!=NULL)
	{
		int depth=1;
		int lcdepth,rcdepth;

		if (T->lc!=NULL)
			lcdepth=getdepth(T->lc);
		else
			lcdepth=0;

		if (T->rc!=NULL)
			rcdepth=getdepth(T->rc);
		else
			rcdepth=0;

		if (lcdepth>rcdepth)
			depth=depth+lcdepth;
		else
			depth=depth+rcdepth;

		return depth;
	}
}

int main()
{
	char str[51];
	while(scanf("%s",str)!=EOF)
	{
		BiTNode* T;
		int n=0;
		CreateTree(T,str,n);
		InOrder(T);
		printf("\n");
		PostOrder(T);
		printf("\n");
		int numleaf=0;
		CountLeaf(T,numleaf);
		printf("%d\n",numleaf);
		int depth=getdepth(T);
		printf("%d\n",depth);
	}
	return 0;
}