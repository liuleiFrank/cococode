#include<stdio.h>
#include<stdlib.h>

typedef struct LNode{
	int data;
	struct LNode* next;
}LNode;

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		LNode* L=(LNode*) malloc(sizeof(LNode));
		L->next=NULL;
		for (int kk=1;kk<=n;kk++)
		{
			int key;
			scanf("%d",&key);
			LNode* S=(LNode*) malloc(sizeof(LNode));
			S->data=key;
			S->next=L->next;
			L->next=S;
		}

		printf("%d\n",n);
		LNode* p=L->next;
		while(p->next!=NULL)
		{
			printf("%d ",p->data);
			p=p->next;
		}
		printf("%d\n",p->data);



		p=L->next;
		while(p->next!=NULL)
		{
			
			LNode*q=p;
			
			while(q->next->next!=NULL)
			{
				if (q->next->data==p->data)
				{
					n--;
					LNode* w=q->next;
					q->next=q->next->next;
					free(w);
				}
				else 
					q=q->next;
			}

			if (q->next->data==p->data)
			{
				n--;
				LNode* w=q->next;
				q->next=q->next->next;
				free(w);
			}
			
			if (p->next!=NULL)
				p=p->next;
			
		}
		
		printf("%d\n",n);
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