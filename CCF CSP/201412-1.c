#include <stdio.h>

int main()
{
	int hash[1001];
	int P[1001];
	int n,a;
	while (scanf("%d",&n)!=EOF)
	{
		for (int i=1;i<=n;i++)
			hash[i]=0;
		for (int i=1;i<=n;i++)
		{
			scanf("%d",&a);
			P[i]=++hash[a];
		}
		for (int i=1;i<n;i++)
			printf("%d ",P[i]);
		printf("%d",P[n]);
	}
	return 0;
}