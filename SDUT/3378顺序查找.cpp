#include<stdio.h>
int N[10000001];
int main()
{
	int n,k;
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		N[0]=k;
		for (int i=1;i<=n;i++)
			scanf("%d",&N[i]);
		int flag=0;
		for (int i=n;i>0;i--)
		{
			if (N[i]==k)
			{
				printf("%d %d\n",i,n-i+1);
				flag=1;
				break;
			}
		}
		if (flag==0)
			printf("No\n");
	}
	return 0;
}