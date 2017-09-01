//===============================================��Ŀ1444��More is better  �ڽӾ����ʾ�ģ��ڵ�̫���ˣ����ʺϡ�
#include<stdio.h>
int visited[1001];
int adj[1001][1001];
int n=1001;
int m;

void DFS(int n,int v,int *count)
{
	visited[v]=1;
	(*count)++;
	for (int j=0;j<n;j++)
		if (adj[v][j]==1 && visited[j]==0)
			DFS(n,j,count);
}

int main()
{
	while(scanf("%d ",&m)!=EOF)
	{
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

		int count[1001]={0};
		int num=-1;
		for (int i=0;i<n;i++)
		{
			if (visited[i]==0)
			{
				num++;
				DFS(n,i,&count[num]);// ��һ�������ӵĶ��㿪ʼ�������������
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