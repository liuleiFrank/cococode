// ==========================================题目1012：畅通工程
//思路：求图中的连通分量，需要建设的道路条数为连通分量数目减1
#include<stdio.h>
int visited[1001];
int adj[1001][1001];
int n,m;

void DFS(int n,int v)
{
	visited[v]=1;
	for (int j=0;j<n;j++)
		if (adj[v][j]==1 && visited[j]==0)
			DFS(n,j);
}

int main()
{
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		if (n==0)// 如果顶点数为0，结束
			return 0;

		for (int i=0;i<n;i++)// 初始化邻接矩阵
			for (int j=0;j<n;j++)
				adj[i][j]=0;

		int s,t;
		for (int i=0;i<m;i++)// 输入邻接矩阵
		{
			scanf("%d %d",&s,&t);
			adj[s-1][t-1]=1;
			adj[t-1][s-1]=1;
		}

		for (int i=0;i<n;i++)// 初始化visited 矩阵
			visited[i]=0;

		//求连通分量的个数
		int count=0;//统计连通分量数目
		for (int i=0;i<n;i++)
		{
			if (visited[i]==0)
			{
				DFS(n,i);// 深度优先搜索
				count++;
			}
		}
		printf("%d\n",count-1);
	}
	return 0;
}