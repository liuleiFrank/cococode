#include<stdio.h>

long int a[100001];
int N;

int OneSort(int low,int high)
{
	a[0]=a[low];
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
	return low;
}

void myprintf(int N)
{
	for (int i=1;i<N;i++)
		printf("%ld ",a[i]);
	printf("%ld\n",a[N]);
}

void Sort(int low,int high)
{
	if (low < high)
	{
		int o=OneSort(low,high);

		Sort(low,o-1);
		Sort(o+1,high);
	}
}

int main()
{
	while(scanf("%d",&N)!=EOF)
	{
		for(int i=1;i<=N;i++)
			scanf("%ld",&a[i]);
		Sort(1,N);
		myprintf(N);
	}
	return 0;
}
