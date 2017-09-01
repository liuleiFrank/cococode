//===============================================题目1444：More is better  邻接表表示,内存还是超了
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 1000

int visited[MAX_SIZE];
int count[MAX_SIZE];

typedef struct ArcNode
{
	int adjvex;
	struct ArcNode* nextarc;
}ArcNode;

typedef struct VNode
{
	int data;
	ArcNode*  firstarc;
}VNode,AdjList[MAX_SIZE];

AdjList AL;

void DFS(int v,int &flag)
{
	ArcNode *p;
	visited[v]=1;
	flag++;
	p=AL[v].firstarc;
	while(p!=NULL)
	{
		if (visited[p->adjvex]==0)
			DFS(p->adjvex,flag);
		p=p->nextarc;
	}
}

int main()
{
	int n;
	while(scanf("%d ",&n)!=EOF)
	{
		for (int i=0;i<MAX_SIZE;i++)
			visited[i]=0;

		for (int i=0;i<MAX_SIZE;i++)
		{
			AL[i].data=i;
			AL[i].firstarc=NULL;
		}

		for (int i=0;i<n;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);

			ArcNode * p;
			p = (ArcNode *)malloc(sizeof(ArcNode));
			p->adjvex = b-1;
			p->nextarc = AL[a-1].firstarc;
			AL[a-1].firstarc=p;

			ArcNode *q;
			q = (ArcNode *)malloc(sizeof(ArcNode));
			q->adjvex = a-1;
			q->nextarc = AL[b-1].firstarc;
			AL[b-1].firstarc=q;
		}

		int num=-1;
		for (int i=0;i<MAX_SIZE;i++)
		{
			if (visited[i]==0)
			{
				int flag=0;
				DFS(i,flag);
				count[++num]=flag;
			}
		}

		int max=0;
		for(int i=0;i<num;i++)
			if (count[i]>max)
				max=count[i];
		printf("%d\n",max);
	}
	return 0;
}