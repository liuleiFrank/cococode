#include<stdio.h>

long int a[100001];

void OneSort(int N)
{
	a[0]=a[1];
	int low=1;
	int high=N;
	while(low!=high)
	{
		while(a[high]>=a[0] && low!=high)
			high--;
		a[low]=a[high];
		while(a[low]<=a[0] && low!=high)
			low++;
		a[high]=a[low];
	}
	a[low]=a[0];
}

void myprintf(int N)
{
	for (int i=1;i<N;i++)
		printf("%ld ",a[i]);
	printf("%ld\n",a[N]);
}

int main()
{
	int N;
	while(scanf("%d",&N)!=EOF)
	{
		for(int i=1;i<=N;i++)
			scanf("%ld",&a[i]);
		OneSort(N);
		myprintf(N);
	}
	return 0;
}