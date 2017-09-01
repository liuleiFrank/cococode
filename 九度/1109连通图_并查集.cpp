// ==========================================题目1109：连通图_并查集

#include<stdio.h>
int Tree[1001];

int findRoot(int x)
{
	if (Tree[x]==-1)
		return x;
	else
	{
		int temp=findRoot(Tree[x]);
		Tree[x]=temp;
		return temp;
	}
}

int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m) && n!=0)
	{
		for (int i=0;i<n;i++)
			Tree[i]=-1;

		for (int i=0;i<m;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			int rx,ry;
			rx=findRoot(x-1);
			ry=findRoot(y-1);
			if(rx!=ry)
				Tree[rx]=ry;
		}

		int count=0;
		for (int i=0;i<n;i++)
			if (Tree[i]==-1)
				count++;
		if (count==1)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}