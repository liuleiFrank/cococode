// ≤Â»Î≈≈–Ú
#include<stdio.h>

int A[101];

void InsertionSort(int N)
{
	for (int i=2;i<=N;i++)
		if (A[i]<A[i-1])
		{
			A[0]=A[i];
			int j;
			for (j=i-1;A[j]>A[0];j--)
				A[j+1]=A[j];
			A[j+1]=A[0];
		}
}

int main()
{
	int N;
	scanf("%d",&N);
	for (int i=1;i<=N;i++)
		scanf("%d",&A[i]);

	InsertionSort(N);

	for (int i=1;i<=N;i++)
		printf("%d ",A[i]);

	printf("\n");
	return 0;
}

