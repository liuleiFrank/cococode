#include<stdio.h>

int R[21];

int findRoot(int x)
{
	if (R[x]==-1)
		return x;
	else
	{
		int temp=findRoot(R[x]);
		R[x]=temp;
		return temp;
	}
}

int main()
{
	int T,N,M;
	scanf("%d",&T);
	for (int k=0;k<T;k++)
	{
		scanf("%d%d",&N,&M);

		for (int i=1;i<=N;i++)
			R[i]=-1;

		int x,y;
		for (int i=1;i<=M;i++)
		{
			scanf("%d%d",&x,&y);
			int rx=findRoot(x);
			int ry=findRoot(y);
			if(rx!=ry)
				R[rx]=ry;
		}

		int count=0;
		for (int i=1;i<=N;i++)
			if(R[i]==-1)
				count++;

		printf("%d\n",count);
	}
	return 0;
}
