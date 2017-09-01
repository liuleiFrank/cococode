#include<stdio.h>
#include<stdlib.h>

typedef struct LNode{
	int data;
	struct LNode* next;
}LNode;

int main()
{
	int N;
	while(scanf("%d",&N)!=EOF)
	{
		LNode* J=(LNode*)malloc (sizeof(LNode));
		J->next=NULL;
		LNode* j=J;
		LNode* O=(LNode*)malloc (sizeof(LNode));
		O->next=NULL;
		LNode* o=O;
		int jj=0;
		int oo=0;
		for (int kk=1;kk<=N;kk++)
		{
			int key;
			scanf("%d",&key);
			if (key%2==0)//o
			{
				LNode* S=(LNode*)malloc (sizeof(LNode));
				S->data=key;
				S->next=o->next;
				o->next=S;
				o=S;
				oo++;
			}
			else//j
			{
				LNode* S=(LNode*)malloc (sizeof(LNode));
				S->data=key;
				S->next=j->next;
				j->next=S;
				j=S;
				jj++;
			}
		}

		printf("%d %d\n",oo,jj);

		LNode* p=O->next;
		while(p->next!=NULL)
		{
			printf("%d ",p->data);
			p=p->next;
		}
		printf("%d\n",p->data);

		LNode* q=J->next;
		while(q->next!=NULL)
		{
			printf("%d ",q->data);
			q=q->next;
		}
		printf("%d\n",q->data);
	}
	return 0;
}