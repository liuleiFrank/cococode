#include<stdio.h>
int a[100001];
int b[100001];
int count1;
int count2;

int OneSort(int low,int high)
{
	a[0]=a[low];
	while(low<high)
	{		
		while(low<high && a[high]>=a[0])
			high--;
		if (a[low]!=a[high])
			count2++;
		a[low]=a[high];
		while(low<high && a[low]<=a[0])
			low++;
		if (a[low]!=a[high])
			count2++;
		a[high]=a[low];
	}
	a[low]=a[0];
	return low;
}

void QSort(int low,int high)
{
	if(low<high)
	{
		int o=OneSort(low,high);
		QSort(low,o-1);
		QSort(o+1,high);
	}
}

void MSort(int N)
{
	for (int i=N-1;i>0;i--)
		for (int j=1;j<=N-1;j++)
			if (b[j]>b[j+1])
			{
				int temp=b[j];
				b[j]=b[j+1];
				b[j+1]=temp;
				count1++;
			}
}

int main()
{
	int N;
	while(scanf("%d",&N)!=EOF)
	{
		for (int i=1;i<=N;i++)
		{
			scanf("%d",&a[i]);
			b[i]=a[i];
		}
		count1=0;
		count2=0;
		MSort(N);
		QSort(1,N);
		printf("%d %d\n",count1,count2);
	}
	return 0;
}
