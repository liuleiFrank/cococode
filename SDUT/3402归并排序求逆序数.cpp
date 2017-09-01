#include<stdio.h>

int a[100001];
int temp[100001];
long int  sum;

void Merge(int l,int r,int m)
{
	int i = l;
	int j = m + 1;
	int k = l;

	while(i<=m && j<=r)
	{
		if(a[j] < a[i])
		{
			sum = sum + ( m - i + 1);
			temp[k++] = a[j++];
		}
		else
			temp[k++] = a[i++];
	}

	while(i<=m)
		temp[k++] = a[i++];
	while(j<=r)
		temp[k++] = a[j++];

	for(i = l;i<=r;i++)
		a[i] = temp[i];
}

void Mergesort(int l,int r)
{
	if(l<r)
	{
		int m = (l + r) / 2;
		Mergesort(l,m);
		Mergesort(m+1,r);
		Merge(l,r,m);
	}
}

int main()
{
	int N;
	while(scanf("%d",&N)!=EOF)
	{
		for(int j = 0;j < N;j++)
			scanf("%d",&a[j]);
		sum = 0;
		Mergesort(0,N-1);
		printf("%ld\n",sum);
	}
	return 0;
}