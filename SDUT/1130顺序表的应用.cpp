#include<stdio.h>
int a[1001];

int main()
{
	int n,count,key,flag;

	while(scanf("%d",&n)!=EOF)
	{
		scanf("%d",&a[0]);
		count = 1;

		for (int i=1;i<=n-1;i++)
		{
			scanf("%d",&key);
			flag=0;
			for ( int j=0;j<count;j++)
			{
				if (a[j]==key)
				{
					flag=1;
					break;
				}
			}

			if (flag==0)
				a[count++]=key;
		}

		printf("%d\n",count);
		for (int i=0;i<count;i++)
			printf("%d ",a[i]);
	}
	return 0;
}