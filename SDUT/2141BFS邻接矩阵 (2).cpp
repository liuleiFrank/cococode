#include<stdio.h>

typedef struct MGraph{
	int arcs[101][101];
	int vexnum;
	int arcnum;
}MGraph;

int visited[101];

void BFS(MGraph G,int t)
{
	int queue[101];
	int rear=-1;
	int front=-1;
	queue[++rear]=t;
	visited[t]=1;
	while(front!=rear)
	{
		printf("%d ",queue[++front]);
		for (int j=0;j<G.vexnum;j++)
		{
			if (G.arcs[ queue[front] ][j]==1 && visited[j]==0)
			{
				queue[++rear]=j;
				visited[j]=1;
			}
		}
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	for (int ii=0;ii<n;ii++)
	{
		int k,m,t;
		scanf("%d%d%d",&k,&m,&t);
		MGraph G;
		G.arcnum=m;
		G.vexnum=k;

		for (int i=0;i<k;i++)
		{
			visited[i]=0;
			for (int j=0;j<k;j++)
				G.arcs[i][j]=0;
		}

		int x,y;
		for (int i=0;i<m;i++)
		{
			scanf("%d%d",&x,&y);
			G.arcs[x][y]=1;
			G.arcs[y][x]=1;
		}

		BFS(G,t);
		printf("\n");
	}
	return 0;
}