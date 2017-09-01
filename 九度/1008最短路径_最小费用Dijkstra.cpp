//��Ŀ1008�����·������
#include<stdio.h>

int E[1001][1001];//�ڽӾ���
int C[1001][1001];//���þ���
int dis[1001][2];
int book[1001];
int inf=1000000;

int main()
{
	int N,M;
	while(scanf("%d %d",&N,&M) && (N+M)!=0)
	{
		//��ʼ���ڽӾ��󡢷��þ���
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

		//����ߣ������ڽӾ��󡢷��þ���
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
		//��ʼ��dis���飬�����ʾ�Ӷ���s�����������̾��루��ʼ��
		for (int i=1;i<=N;i++)
		{
			dis[i][0]=E[s][i];
			dis[i][1]=C[s][i];
			book[i]=0;
		}
		book[s]=1;//��¼�����Ƿ��������s�����·���������������Ϊ1������Ϊ0.

		int flag,min;
		for (int k=1;k<=N-1;k++) //Dijkstra�㷨���ظ�N-1��
		{
			min =inf;
			//��dis��δ��book�б���Ϊ1����̵�·����1��i��
			for (int i=1;i<N;i++)
				if (dis[i][0]<min && book[i]==0)
				{
					min=dis[i][0];
					flag=i;
				}

			book[flag]=1;//���ҵ������·���Ķ�����Ϊ1
			
			//������flag���������Ķ�������·�����ȡ�����
			for (int i=1;i<=N;i++)
			{
				if (book[i]==0 && dis[i][0] > dis[flag][0]+E[flag][i])
				{
					dis[i][0]=dis[flag][0]+E[flag][i];
					dis[i][1]=dis[flag][1]+C[flag][i];
				}
				//ע�⣡�����������Ŀ��ǣ��������·������һ�������Ƿ��õ͵�Ӧ�ñ�ѡȡ
				else if (book[i]==0 && dis[i][0]==dis[flag][0]+E[flag][i] && dis[i][1]>dis[flag][1]+C[flag][i])
					dis[i][1]=dis[flag][1]+C[flag][i];
			}
		}

		printf("%d %d\n",dis[t][0],dis[t][1]); //����s�붥��t֮�����̾��롢����
	}
	return 0;
}
