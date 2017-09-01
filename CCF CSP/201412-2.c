#include <stdio.h>

int M[501][501];

void order(int n,int x,int y)
{
	int xx=x;
	int yy=y;
	if (x==y==1)
		printf("%d ",M[x][y]);
	else if(x==y==n)
		printf("%d",M[x][y]);
	else if (x<y)
	{
		for (int k=x;k<=y;k++)
			printf("%d ",M[xx++][yy--]);
	}
	else if (x>y)
	{
		for (int k=y;k<=x;k++)
			printf("%d ",M[xx--][yy++]);
	}
}

int main()
{
	int n;
	while (scanf("%d",&n)!=EOF)
	{
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				scanf("%d",&M[i][j]);

		//左上三角形中 对角线起始遍历点
		for (int i=1;i<=n;i++)
		{
			if ((i%2)==0)
				order(n,1,i);
			else 
				order(n,i,1);
		}

		//右下三角形中 对角线起始遍历点
		for (int i=2;i<=n;i++)
		{
			if (n%2==0)
			{
				if ((i%2)==0)
					order(n,n,i);
				else 
					order(n,i,n);
			}
			else 
			{
				if ((i%2)==0)
					order(n,i,n);
				else 
					order(n,n,i);
			}
		}
		printf("\n");
	}
	return 0;
}