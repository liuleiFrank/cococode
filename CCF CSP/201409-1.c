#include <stdio.h>
int hash[10001];
int main()
{
	int n,a;
	while (scanf("%d",&n)!=EOF)
	{
		int count=0;
		for (int i=0;i<=10000;i++)
			hash[i]=0;
		for (int i=1;i<=n;i++)
		{
			scanf("%d",&a);
			hash[a]=1;
		}
		for (int i=1;i<=10000;i=i+2)
		{
			if (hash[i]==1)
			{
				if (hash[i+1]==1)
					count++;
				if (hash[i-1]==1)
					count++;
			}
		}
		printf("%d\n",count);
	}
	return 0;
}