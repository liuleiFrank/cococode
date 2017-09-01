#include<stdio.h>
#include<stdlib.h>

typedef struct DNode{
	int data;
	struct DNode* pi;
	struct DNode* ne;
}DNode;


int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		DNode* L=(DNode*)malloc(sizeof(DNode));
		L->ne=NULL;
		DNode* p=L;

		for (int kk=1;kk<=n;kk++)
		{
			int key;
			scanf("%d",&key);
			DNode* S=(DNode*)malloc(sizeof(DNode));
			S->data=key;

			S->ne=p->ne;
			S->pi=p;
			p->ne=S;
			p=p->ne;
		}

		for (int kk=1;kk<=m;kk++)
		{
			int tag;
			scanf("%d",&tag);
			p=L;

			if (p->ne->data==tag)
			{
				printf("%d\n",p->ne->ne->data);
			}
			else
			{
				while(p->ne!=NULL)
				{
					p=p->ne;
					if (p->data==tag && p->ne!=NULL )
					{
						printf("%d %d\n",p->pi->data,p->ne->data);
						break;
					}
					else if (p->data==tag && p->ne==NULL )
					{
						printf("%d\n",p->pi->data);
						break;
					}
				}
			}
		}
	}

	return 0;
}