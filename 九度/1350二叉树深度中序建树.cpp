#include <stdio.h>
#include <stdlib.h>

typedef struct BiTNode
{
	int data;
	struct BiTNode* lc;
	struct BiTNode* rc;
}BiTNode;

BiTNode* queue[100];

void PreOrder(BiTNode* T)
{
	if (T!=NULL)
	{
		printf("%d ",T->data);
		PreOrder(T->lc);
		PreOrder(T->rc);
	}
}

int getdepth(BiTNode* T)
{
	int depth,ld,rd;
	if (T==NULL)
		depth=0;
	else
	{
		ld=getdepth(T->lc);
		rd=getdepth(T->rc);

		if (ld>rd)
			depth=ld+1;
		else 
			depth=rd+1;
	}
	return depth;
}

int main()
{
	int n,front,rear,l,r;
	while (scanf("%d",&n)!=EOF)
	{
		front=-1;
		rear=-1;
		
		BiTNode* T=(BiTNode*)malloc(sizeof(BiTNode));
		T->data=1;
		
		queue[++rear]=T;
		
		while (rear!=front)
		{
			queue[++front];
			scanf("%d %d",&l,&r);
			
			if (l==-1)
				queue[front]->lc=NULL;
			else
			{
				
				BiTNode* S1=(BiTNode*)malloc(sizeof(BiTNode));
				S1->data=l;
				queue[front]->lc=S1;
				queue[++rear]=S1;
			}
			
			if (r==-1)
				queue[front]->rc=NULL;
			else
			{
				BiTNode* S2=(BiTNode*)malloc(sizeof(BiTNode));
				S2->data=r;
				S2->lc=NULL;
				S2->rc=NULL;
				queue[front]->rc=S2;
				queue[++rear]=S2;
			}		
		}
		
		printf("%d\n", getdepth(T) );	
	}
	return 0;
}