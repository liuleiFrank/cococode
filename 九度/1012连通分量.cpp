// ==========================================��Ŀ1012����ͨ����
//˼·����ͼ�е���ͨ��������Ҫ����ĵ�·����Ϊ��ͨ������Ŀ��1
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
		if (n==0)// ���������Ϊ0������
			return 0;

		for (int i=0;i<n;i++)// ��ʼ���ڽӾ���
			for (int j=0;j<n;j++)
				adj[i][j]=0;

		int s,t;
		for (int i=0;i<m;i++)// �����ڽӾ���
		{
			scanf("%d %d",&s,&t);
			adj[s-1][t-1]=1;
			adj[t-1][s-1]=1;
		}

		for (int i=0;i<n;i++)// ��ʼ��visited ����
			visited[i]=0;

		//����ͨ�����ĸ���
		int count=0;//ͳ����ͨ������Ŀ
		for (int i=0;i<n;i++)
		{
			if (visited[i]==0)
			{
				DFS(n,i);// �����������
				count++;
			}
		}
		printf("%d\n",count-1);
	}
	return 0;
}