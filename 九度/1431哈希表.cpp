//ÌâÄ¿1431£ºSort      Hash±í
#include<stdio.h>
int a[10000001];
int base=500000;
int main()
{
	int n,m,x;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for (int i=0;i<10000001;i++)
			a[i]=0;

		for (int i=0;i<n;i++)
		{
			scanf("%d",&x);
			a[x+base]=1;
		}
		int count=0;
		int i;
		for (i=10000001;count<m;i--)
			if (a[i]==1)
			{
				if (count < m-1)
					printf("%d ",i-base);
				else 
					printf("%d",i-base);
				count++;
			}
		printf("\n");
	}
	return 0;
}
		
