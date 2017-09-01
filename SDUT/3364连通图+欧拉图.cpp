#include<stdio.h>

int R[1001];
int D[1001];

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
	int T;
	scanf("%d",&T);
	for (int ii=0;ii<T;ii++)
	{
		int N,M;
		scanf("%d%d",&N,&M);

		for (int jj=1;jj<=N;jj++)
		{
			R[jj]=-1;
			D[jj]=0;
		}

		for (int jj=0;jj<M;jj++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			D[x]++;
			D[y]++;
			int rx=findRoot(x);
			int ry=findRoot(y);
			if (rx!=ry)
				R[rx]=ry;
		}

		int count=0;
		int flag=0;
		for (int jj=1;jj<=N;jj++)
		{
			if (R[jj]==-1)
				count++;
			if (D[jj]%2 != 0)
				flag=1;
		}

		if(count==1 && flag==0)
			printf("%d\n",1);
		else
			printf("%d\n",0);

	}
	return 0;
}