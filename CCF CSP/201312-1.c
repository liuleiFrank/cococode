#include <stdio.h>

int A[10001];

int n;

int main()
{
	while (scanf("%d",&n)!=EOF)
	{
		int i;
		for (i=1;i<=10000;i++)
			A[i]=0;
		
		for (i=1; i<=n; i++)
		{
			int temp;
			scanf("%d",&temp);
			A[temp]++;
		}
		
		int max=0;
		int flag;
		for (i=10000;i>=1;i--)
		{
			if (A[i]>=max)
			{
				max=A[i];
				flag=i;
			}
		}
		
		printf("%d\n",flag);	
		
	}
	return 0;
}
