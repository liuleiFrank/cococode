#include <stdio.h>
int A[1001][1001];
int main()
{
	int m,n;
	while (scanf("%d %d",&m,&n)!=EOF)
	{
		int i,j;
		for (i=1;i<=m;i++)
			for (j=1;j<=n;j++)
				scanf("%d",&A[i][j]);
		for (i=n;i>=1;i--)
		{
			for (j=1;j<m;j++)
				printf("%d ",A[j][i]);
			printf("%d\n",A[m][i]);
		}
	}
	return 0;
}