#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
	char str[15];
	struct Node* next;
}Node;

typedef struct VNode
{
	int data;
	Node* fir;
}VNode;

VNode  C[2001];

int main()
{
	int N,M;
	while (scanf("%d %d",&N,&M)!=EOF)
	{
		for (int i=1;i<=M;i++)
		{
			C[i].data=0;
			C[i].fir=NULL;
		}

		for (int kk=1;kk<=N;kk++)
		{
			char name[15];
			int num,key;
			scanf("%s",name);
			scanf("%d",&num);
			for (int k=1;k<=num;k++)
			{
				scanf("%d",&key);
				Node* S=(Node*)malloc(sizeof(Node));
				strcpy(S->str,name);
				S->next=NULL;
				Node* p=C[key].fir;
				if (p==NULL)
				{
					C[key].data++;
					C[key].fir=S;
				}
				else 
				{
					while (p->next!=NULL)
					{
						if (strcmp(p->next->str,S->str)>0)
							break;
						p=p->next;
					}
					if (strcmp(p->str,S->str)>0)
					{
						C[key].fir=S;
						S->next=p;
						C[key].data++;
					}
					else 
					{
						S->next=p->next;
						p->next=S;
						C[key].data++;
					}
				}	
			}
		}
		
		for (int i=1;i<=M;i++)
		{
			printf("%d %d\n",i,C[i].data);
			Node* p=C[i].fir;
			while (p!=NULL)
			{
				printf("%s\n",p->str);
				p=p->next;
			}
		}
	}
	return 0;
}