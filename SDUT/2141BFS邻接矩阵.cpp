#include<stdio.h>

int Adj[101][101];
int Book[101];
int queue[101];

void BFS(int t,int k)
{
	int num=-1;
	int flag=-1;
	queue[++num]=t;
	Book[t]=1;
	while(flag!=num)
	{
		printf("%d ",queue[++flag]);
		for (int j=0;j<k;j++)
		{
			if (Adj[queue[flag]][j]==1 && Book[j]==0)
			{
				queue[++num]=j;
				Book[j]=1;
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
		for (int i=0;i<k;i++)
		{
			Book[i]=0;
			for (int j=0;j<k;j++)
				Adj[i][j]=0;
		}

		int x,y;
		for (int i=0;i<m;i++)
		{
			scanf("%d%d",&x,&y);
			Adj[x][y]=1;
			Adj[y][x]=1;
		}

		BFS(t,k);
		printf("\n");
	}
	return 0;
}