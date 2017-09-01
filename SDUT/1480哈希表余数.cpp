#include <stdio.h>
#define N 1000001
long int hash[N];//存储数值
int hashL[N];//存储个数

int main()
{
	int n,i,j;
	while (scanf("%d",&n)!=EOF)
	{
		for (i=0;i<N;i++)
		{
			hash[i]=-1;
			hashL[i]=0;
		}

		for (i=0;i<n;i++)
		{
			long int key;
			scanf("%ld",&key);

			int yu=key % N;

			//若空，直接存入
			if (hash[yu]==-1)
			{
				hash[yu]=key;
				hashL[yu]++;
			}
			//若不空，往后找空的 或 相同的值
			else 
			{
				for (j=yu; ;j++)
				{
					if(j>N)
						j=0;//循环回来找存储的地方
					if (hash[j]==-1)
					{
						hash[j]=key;
						hashL[j]++;
						break;
					}
					else if (hash[j]==key)
					{
						hashL[j]++;
						break;
					}
				}
			}
		}

		int max=0;
		long int minvalue=100000000;
		for (i=0;i<=N;i++)
		{
			if ( hashL[i]>max || ( hashL[i]==max && hash[i]<minvalue ) )
			{
				max=hashL[i];
				minvalue=hash[i];
			}
		}
		printf("%ld %d\n",minvalue,max);
	}
	return 0;
}