//题目1008：最短路径问题
#include<stdio.h>

int E[1001][1001];//邻接矩阵
int C[1001][1001];//费用矩阵
int dis[1001][2];
int book[1001];
int inf=1000000;

int main()
{
	int N,M;
	while(scanf("%d %d",&N,&M) && (N+M)!=0)
	{
		//初始化邻接矩阵、费用矩阵
		for (int i=1;i<=N;i++)
			for (int j=1;j<=N;j++)
				if (i==j)
				{
					E[i][j]=0;
					C[i][j]=0;
				}
				else
				{
					E[i][j]=inf;
					C[i][j]=inf;
				}

		//输入边，构造邻接矩阵、费用矩阵
		int x,y,v,c;
		for (int i=1;i<=M;i++)
		{
			scanf ("%d %d %d %d",&x,&y,&v,&c);
			E[x][y]=v;
			E[y][x]=v;
			C[x][y]=c;
			C[y][x]=c;

		}
		int s,t;
		scanf("%d %d",&s,&t);
		//初始化dis数组，这里表示从顶点s到各顶点的最短距离（初始）
		for (int i=1;i<=N;i++)
		{
			dis[i][0]=E[s][i];
			dis[i][1]=C[s][i];
			book[i]=0;
		}
		book[s]=1;//记录顶点是否已求出到s的最短路径，若已求出则置为1，否则为0.

		int flag,min;
		for (int k=1;k<=N-1;k++) //Dijkstra算法，重复N-1次
		{
			min =inf;
			//找dis中未在book中被置为1的最短的路径（1到i）
			for (int i=1;i<N;i++)
				if (dis[i][0]<min && book[i]==0)
				{
					min=dis[i][0];
					flag=i;
				}

			book[flag]=1;//将找到的最短路径的顶点置为1
			
			//更新与flag顶点相连的顶点的最短路径长度、费用
			for (int i=1;i<=N;i++)
			{
				if (book[i]==0 && dis[i][0] > dis[flag][0]+E[flag][i])
				{
					dis[i][0]=dis[flag][0]+E[flag][i];
					dis[i][1]=dis[flag][1]+C[flag][i];
				}
				//注意！加入费用问题的考虑，如果两条路径长度一样，但是费用低的应该被选取
				else if (book[i]==0 && dis[i][0]==dis[flag][0]+E[flag][i] && dis[i][1]>dis[flag][1]+C[flag][i])
					dis[i][1]=dis[flag][1]+C[flag][i];
			}
		}

		printf("%d %d\n",dis[t][0],dis[t][1]); //顶点s与顶点t之间的最短距离、费用
	}
	return 0;
}
