#include<stdio.h>
#include<stdlib.h>

int k,m,t;

typedef struct ArcNode{
	int data;
	struct ArcNode* nextarc;
}ArcNode;

typedef struct VNode{
	int v;
	struct ArcNode* firstarc;
	struct ArcNode* flag; //一直指向最后一个节点，方便尾插法
}VNode,VList[101];

int queue[200];//队列相关
int front=-1;
int rear=-1;

int book[101];//是否遍历过的标志数组

void BFS(VList VecList)
{
	queue[++front]=t;
	book[t]=1;

	while(front!=rear)
	{
		rear++;
		printf("%d ",queue[rear]);

		ArcNode* p=VecList[queue[rear]].firstarc;
		while(p!=NULL)
		{
			if (book[p->data]==0)
			{
				queue[++front]=p->data;
				book[p->data]=1;
			}
			p=p->nextarc;
		}
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	VList VecList;
	for (int kkk=1;kkk<=n;kkk++)
	{
		scanf("%d %d %d",&k,&m,&t);

		for (int i=0;i<k;i++)
		{
			book[i]=0;
			VecList[i].v=i;
			VecList[i].firstarc=NULL;
			VecList[i].flag=NULL;
		}

		for (int kk=1;kk<=m;kk++)
		{
			int u,v;
			scanf("%d%d",&u,&v);

			ArcNode* S;

			S=(ArcNode*)malloc (sizeof(ArcNode));
			S->data=v;
			S->nextarc=NULL;
			if(VecList[u].flag==NULL)
			{
				VecList[u].firstarc=S;
				VecList[u].flag=S;
			}
			else
			{
				VecList[u].flag->nextarc=S;
				VecList[u].flag=S;	
			}

			S=(ArcNode*)malloc (sizeof(ArcNode));
			S->data=u;
			S->nextarc=NULL;
			if(VecList[v].flag==NULL)
			{
				VecList[v].firstarc=S;
				VecList[v].flag=S;
			}
			else
			{
				VecList[v].flag->nextarc=S;
				VecList[v].flag=S;
			}
		}

		BFS(VecList);
		printf("\n");
	}

	return 0;
}