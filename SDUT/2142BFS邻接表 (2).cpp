#include<stdio.h>
#include<stdlib.h>

typedef struct ArcNode{
	int adjvex;
	struct ArcNode* nextarc;
}ArcNode;

typedef struct VNode{
	int data;
	ArcNode* firstarc;
	ArcNode* flag;
}VNode;

typedef struct ALGraph{
	VNode vertices[101];
	int vexnum;
	int arcnum;
}ALGraph;

int visited[101];

void BFS(ALGraph G,int t)
{
	int queue[200];
	int front=-1;
	int rear=-1;

	queue[++rear]=t;
	visited[t]=1;

	ArcNode* p;
	while(front!=rear)
	{
		int q=queue[++front];
		printf("%d ",q);

		p=G.vertices[q].firstarc;
		while(p!=NULL)
		{
			if (visited[p->adjvex]==0)
			{
				queue[++rear]=p->adjvex;
				visited[p->adjvex]=1;
			}
			p=p->nextarc;
		}
	}
}

int main()
{
	int n;
	int k,m,t;
	scanf("%d",&n);
	for (int kkk=1;kkk<=n;kkk++)
	{
		scanf("%d %d %d",&k,&m,&t);
		ALGraph G;
		G.arcnum=m;
		G.vexnum=k;

		for (int i=0;i<k;i++)
		{
			G.vertices[i].data=i;
			G.vertices[i].firstarc=NULL;
			G.vertices[i].flag=NULL;
			visited[i]=0;
		}

		for (int i=1;i<=m;i++)
		{
			int u,v;
			scanf("%d %d",&u,&v);

			ArcNode* S=(ArcNode*) malloc (sizeof(ArcNode));

			S->adjvex=v;
			S->nextarc=NULL;

			if (G.vertices[u].flag!=NULL)
			{
				G.vertices[u].flag->nextarc=S;
				G.vertices[u].flag=S;
			}
			else
			{
				G.vertices[u].firstarc=S;
				G.vertices[u].flag=S;
			}

			ArcNode* T=(ArcNode*) malloc (sizeof(ArcNode));
			T->adjvex=u;
			T->nextarc=NULL;

			if (G.vertices[v].flag!=NULL)
			{
				G.vertices[v].flag->nextarc=T;
				G.vertices[v].flag=T;
			}
			else
			{
				G.vertices[v].firstarc=T;
				G.vertices[v].flag=T;
			}
		}

		BFS(G,t);
		printf("\n");

	}
	return 0;
}