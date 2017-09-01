#include <stdio.h>
int A[50001];

void insert(int key,int s,int t)
{
	int i;
	A[s-1]=key;
	for (i=t;A[i]>key;i--)
		A[i+1]=A[i];
	A[i+1]=key;
}

int main()
{
	int n;
	int key;

	while(scanf("%d",&n) && n!=0)
	{

	    int sum=0;
		int i;
		int count=1;

		scanf("%d",&A[1]);

		for (i=2;i<=n;i++)
		{
			scanf("%d",&key);
			insert(key,1,i-1);
		}

		for (i=1;count<=n-1;i=i+2)
		{
		    int a=A[i];
			int b=A[i+1];
			key=a+b;
			sum=sum+key;
			insert(key,i+2,n+count-1);
			count++;
		}

		printf("%d\n",sum);

	}

	return 0;
}

