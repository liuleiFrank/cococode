#include <stdio.h>

int A[101];
int LIS1[101];
int LIS2[101];

int main()
{
	int N;
	while (scanf("%d",&N)!=EOF)
	{
		for (int i=1;i<=N;i++)
		{
			scanf("%d",&A[i]);
			LIS1[i]=0;
			LIS1[i]=0;
		}

		for (int i=1;i<=N;i++)
		{
			int MAX=0;
			for (int j=i-1; j>=1 ;j--)
			{
				if ( LIS1[j]>MAX && A[j]<A[i] )
					MAX=LIS1[j];
			}
			LIS1[i]=MAX+1;
		}
		
		for (int i=N;i>=1;i--)
		{
			int MAX=0;
			for (int j=N; j>i ;j--)
			{
				if (LIS2[j]>MAX  && A[j]<A[i] )
				{
					MAX=LIS2[j];
				}
			}
			LIS2[i]=MAX+1;
		}

	    int MAX=0;
		for (int i=1;i<=N;i++)
		{
			if (LIS1[i]+LIS2[i]>MAX)
			{
				MAX=LIS1[i]+LIS2[i];
			}
		}
		printf ("%d\n",N-(MAX-1));
	}

	return 0;
}