//题目1112：拦截导弹 最长不增\递增子序列LIS 
//最长不增子序列对应最多可以拦截多少导弹
//最长递增子序列对应最少需要多少拦截系统才能把所有拦截所有导弹
#include<stdio.h>
int main()
{
	int k;
	int A[1001];
	int L[1001];
	while(scanf("%d",&k)!=EOF)
	{
		for (int i=0;i<k;i++)
		{
			scanf("%d",&A[i]);
			L[i]=1;
		}

		for (int j=0;j<k;j++)
			for (int i=0;i<j;i++)
				if (A[i]>=A[j] && L[j]<L[i]+1)
					L[j]=L[i]+1;

		int max=1;
		for (int i=0;i<k;i++)
			if(L[i]>max)
				max=L[i];
		printf("%d\n",max);

	}
	return 0;
}

