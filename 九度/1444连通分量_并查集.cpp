//===============================================题目1444：More is better  并查集
#include <stdio.h>
# define N 10000001
int Tree[N];
int sum[N];

int findRoot(int x)
{
	if (Tree [x]==-1)
		return x;
	else
	{
		int temp=findRoot(Tree[x]);
		Tree[x]=temp;
		return temp;
	}
}

int main ()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		for (int i=1;i<N;i++)
		{
			Tree[i]=-1;
			sum[i]=1;
		}

		for (int i=0;i<n;i++)
		{
			int a,b,ra,rb;
			scanf("%d %d",&a,&b);
			ra = findRoot(a);
			rb = findRoot(b);
			if (ra!=rb)
			{
				Tree[ra]=rb;
				sum[rb]=sum[rb]+sum[ra];
			}
		}
		int ans=1;
		for (int i=1;i<=N;i++)
			if (Tree[i]==-1 && sum[i]>ans)
				ans=sum[i];
		printf("%d\n",ans);
	}
	return 0;
}
