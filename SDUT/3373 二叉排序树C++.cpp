// C++  3373 数据结构实验之查找一：二叉排序树
#include<stdio.h>
#include<stdlib.h>

struct BSTNode{
	int data;
	struct BSTNode* lc;
	struct BSTNode* rc;
};

int SearchBST( BSTNode* T ,int key , BSTNode* &p)
{
	if (!T)
		return 0;
	else if(T->data==key)
		return 1;
	else if (key>T->data)
		return SearchBST(T->rc,key,T);
	else if (key<T->data)
		return SearchBST(T->lc,key,T);
}

void InsertBST(BSTNode* &T,int e)
{
	BSTNode* p=NULL;
	if( SearchBST(T,e,p)==0 )
	{
		BSTNode* s=(BSTNode*) malloc (sizeof(BSTNode));
		s->data=e;
		s->lc=s->rc=NULL;

		if (p==NULL)
			T=s;
		else if(e > p->data)
			p->rc=s;
		else if(e < p->data)
			p->lc=s;
	}
}

void InOrder(BSTNode* T,int in[11],int &num)
{
	if (T)
	{
		InOrder(T->lc,in,num);
		in[++num]=T->data;
		InOrder(T->rc,in,num);
	}
}

void PreOrder(BSTNode* T,int pre[11],int &num)
{
	if (T)
	{
		pre[++num]=T->data;
		PreOrder(T->lc,pre,num);
		PreOrder(T->rc,pre,num);
	}
}

int main()
{
	int N,L,e,num,flag;
	int in0[11],in1[11],pre0[11],pre1[11];
	BSTNode* T[100];

	while(scanf("%d %d",&N,&L) && N!=0)
	{
		T[0]=NULL;
		for (int i=0;i<N;i++)
		{
			scanf("%d",&e);
			InsertBST(T[0],e);
		}
		num=-1;
		InOrder(T[0],in0,num);
		num=-1;
		PreOrder(T[0],pre0,num);

		for (int j=1;j<=L;j++)
		{
			T[j]=NULL;
			for (int i=0;i<N;i++)
			{
				scanf("%d",&e);
				InsertBST(T[j],e);
			}
			num=-1;
			InOrder(T[j],in1,num);
			num=-1;
		    PreOrder(T[j],pre1,num);

			flag=0;
			for (int k=0;k<N;k++)
			{
				if (in0[k]!=in1[k] || pre0[k]!=pre1[k])
				{
					flag=1;
					printf("No\n");
					break;
				}
			}
			if (flag==0)
				printf("Yes\n");
		}
	}
	return 0;
}

