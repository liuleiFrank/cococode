#include <stdio.h>

int node[100][100];

int main()
{
	int n;
	while (scanf("%d",&n)!=EOF)
	{
		for (int i=0;i<=99;i++)
			for (int j=0;j<=99;j++)
				node[i][j]=0;

		for (int k=1;k<=n;k++)
		{
			int xmin,ymin,xmax,ymax;
			scanf("%d %d %d %d",&xmin,&ymin,&xmax,&ymax);

			for (int i=xmin;i<xmax;i++)
				for (int j=ymin;j<ymax;j++)
					node[i][j]=1;
		}

		int count=0;

		for (int i=0;i<100;i++)
			for (int j=0;j<100;j++)
				if (node[i][j]==1)
					count++;

		printf("%d\n",count);
	}
	return 0;
}