//题目1447：最短路
#include<stdio.h>

int E[101][101];//邻接矩阵
int dis[101];
int book[101];
int inf=1000000;

int main()
{
	int N,M;
	while(scanf("%d %d",&N,&M) && (N+M)!=0)
	{
		//初始化邻接矩阵
		for (int i=1;i<=N;i++)
			for (int j=1;j<=N;j++)
				if (i==j)
					E[i][j]=0;
				else
					E[i][j]=inf;

		//输出边，构造邻接矩阵
		int x,y,v;
		for (int i=1;i<=M;i++)
		{
			scanf ("%d %d %d",&x,&y,&v);
			E[x][y]=v;
			E[y][x]=v;
		}

		//初始化dis数组，这里表示从顶点1到各顶点的最短距离（初始）
		for (int i=1;i<=N;i++)
		{
			dis[i]=E[1][i];
			book[i]=0;
		}
		book[1]=1;//记录顶点是否已求出到1的最短路径，若已求出则置为1，否则为0.

		for (int k=1;k<=N-1;k++) //Dijkstra算法，重复N-1次
		{
			int min =inf;
			int flag;

			//找dis中未在book中被置为1的最短的路径（1到i）
			for (int i=1;i<N;i++)
				if (dis[i]<min && book[i]==0)
				{
					min=dis[i];
					flag=i;
				}

			book[flag]=1;//将找到的最短路径的顶点置为1

			//更新与flag顶点相连的顶点的最短路径长度
			for (int i=1;i<=N;i++)
				if (book[i]==0 && dis[i] > dis[flag]+E[flag][i])
					dis[i]=dis[flag]+E[flag][i];
		}

		printf("%d\n",dis[N]); //顶点1与顶点N之间的最短距离
	}
	return 0;
}
