#include<stdio.h>
#include<stdlib.h>

typedef struct LNode{
	int data;
	struct LNode* next;
}LNode ;

int main()
{
	int N;
	while(scanf("%d",&N)!=EOF)
	{
		LNode* L=(LNode*) malloc (sizeof(LNode)); 
		L->next=NULL;
		for (int kk=1;kk<=N;kk++)
		{
			int key;
			scanf("%d",&key);
			LNode* S=(LNode*) malloc (sizeof(LNode)); 
			S->data=key;

			if (L->next==NULL)
			{
				S->next=L->next;
				L->next=S;
			}
			else
			{
				LNode* p=L;
				while (p->next!=NULL && p->next->data<key)
					p=p->next;
				S->next=p->next;
				p->next=S;
			}
		}

		LNode* p=L->next;
		while(p->next!=NULL)
		{
			printf("%d ",p->data);
			p=p->next;
		}
		printf("%d\n",p->data);
	}

	return 0;
}