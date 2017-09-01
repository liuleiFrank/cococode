//��Ŀ1447�����·
#include<stdio.h>

int E[101][101];//�ڽӾ���
int dis[101];
int book[101];
int inf=1000000;

int main()
{
	int N,M;
	while(scanf("%d %d",&N,&M) && (N+M)!=0)
	{
		//��ʼ���ڽӾ���
		for (int i=1;i<=N;i++)
			for (int j=1;j<=N;j++)
				if (i==j)
					E[i][j]=0;
				else
					E[i][j]=inf;

		//����ߣ������ڽӾ���
		int x,y,v;
		for (int i=1;i<=M;i++)
		{
			scanf ("%d %d %d",&x,&y,&v);
			E[x][y]=v;
			E[y][x]=v;
		}

		//��ʼ��dis���飬�����ʾ�Ӷ���1�����������̾��루��ʼ��
		for (int i=1;i<=N;i++)
		{
			dis[i]=E[1][i];
			book[i]=0;
		}
		book[1]=1;//��¼�����Ƿ��������1�����·���������������Ϊ1������Ϊ0.

		for (int k=1;k<=N-1;k++) //Dijkstra�㷨���ظ�N-1��
		{
			int min =inf;
			int flag;

			//��dis��δ��book�б���Ϊ1����̵�·����1��i��
			for (int i=1;i<N;i++)
				if (dis[i]<min && book[i]==0)
				{
					min=dis[i];
					flag=i;
				}

			book[flag]=1;//���ҵ������·���Ķ�����Ϊ1

			//������flag���������Ķ�������·������
			for (int i=1;i<=N;i++)
				if (book[i]==0 && dis[i] > dis[flag]+E[flag][i])
					dis[i]=dis[flag]+E[flag][i];
		}

		printf("%d\n",dis[N]); //����1�붥��N֮�����̾���
	}
	return 0;
}
