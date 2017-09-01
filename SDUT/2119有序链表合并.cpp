#include <stdio.h>
#include <stdlib.h>

typedef struct LNode
{
	int data;
	struct LNode* next;
}LNode;

int main()
{
	int M,N,i,j;
	while (scanf("%d %d",&M,&N)!=EOF)
	{
		LNode* L1=(LNode*)malloc (sizeof(LNode));
		L1->next=NULL;
		LNode* p1=L1;
		for (i=1;i<=M;i++)
		{
			int key;
			scanf("%d",&key);
			LNode* S=(LNode*)malloc (sizeof(LNode));
			S->data=key;
			S->next=NULL;
			p1->next=S;
			p1=S;
		}

		LNode* L2=(LNode*)malloc (sizeof(LNode));
		L2->next=NULL;
		LNode* p2=L2;
		for (i=1;i<=N;i++)
		{
			int key;
			scanf("%d",&key);
			LNode* S=(LNode*)malloc (sizeof(LNode));
			S->data=key;
			S->next=NULL;
			p2->next=S;
			p2=S;
		}

		LNode* L=(LNode*)malloc (sizeof(LNode));
		LNode* p=L;
		L->next=NULL;
		p1=L1->next;
		p2=L2->next;
		while (p1!=NULL && p2!=NULL)
		{
			LNode* S=(LNode*)malloc (sizeof(LNode));
			S->next=NULL;
			if (p1->data <= p2->data)
			{
				S->data=p1->data;
				p->next=S;
				p=S;
				p1=p1->next;
			}
			else 
			{
				S->data=p2->data;
				p->next=S;
				p=S;
				p2=p2->next;
			}
		}

		if (p1==NULL)
		{
			while (p2!=NULL)
			{
				LNode* S=(LNode*)malloc (sizeof(LNode));
				S->next=NULL;
				S->data=p2->data;
				p->next=S;
				p=S;
				p2=p2->next;
			}
		}

		if (p2==NULL)
		{
			while (p1!=NULL)
			{
				LNode* S=(LNode*)malloc (sizeof(LNode));
				S->next=NULL;
				S->data=p1->data;
				p->next=S;
				p=S;
				p1=p1->next;
			}
		}
		
		p=L->next;
		while (p!=NULL)
		{
			printf("%d ",p->data);
			p=p->next;
		}
		printf("\n");
	}
	return 0;
}