#include<stdio.h>
#include<stdlib.h>

typedef struct LNode{
	int data;
	struct LNode* next;
}LNode;

int main()
{
	int key1;
	while(scanf("%d",&key1)!=EOF)
	{
		LNode* L=(LNode*) malloc (sizeof(LNode));
		LNode* flag=L;

		LNode* S=(LNode*) malloc (sizeof(LNode));
		S->data=key1;
		flag->next=S;
		flag=S;

		int key;
		while(scanf("%d",&key) && key!=-1)
		{
			LNode* S=(LNode*) malloc (sizeof(LNode));
			S->data=key;
			flag->next=S;
			flag=S;
		}

		flag->next=NULL;

		LNode* p=L->next;
		L->next=NULL;
		LNode* q;
		while(p->next!=NULL)
		{
			q=p;
			p=p->next;
			q->next=L->next;
			L->next=q;
		}

		p->next=L->next;
		L->next=p;

		p=L->next;
		while(p->next!=NULL)
		{
			printf("%d ",p->data);
			p=p->next;
		}
		printf("%d\n",p->data);
	}
	return 0;
}


