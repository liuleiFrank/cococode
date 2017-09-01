#include<stdio.h>

int a[10001];

void ShellSort(int N,int dk)
{
	for (int i=1+dk;i<=N;i++)
		if (a[i]<a[i-dk])
		{
			a[0]=a[i];
			int j;
			for (j=i-dk;j>0 && a[j]>a[0];j=j-dk)
				a[j+dk]=a[j];
			a[j+dk]=a[0];
		}		
}

void myprintf(int N)
{
	for (int i=1;i<N;i++)
		printf("%d ",a[i]);
	printf("%d\n",a[N]);
}

int main()
{
	int N;
	while(scanf("%d",&N)!=EOF)
	{
		for (int i=1;i<=N;i++)
			scanf("%d",&a[i]);

		ShellSort(N,N/2);
		myprintf(N);

		ShellSort(N,1);
		myprintf(N);
	}
	return 0;
}