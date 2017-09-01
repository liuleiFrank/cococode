#include<stdio.h>
int N[1000001];
int main()
{
	int n,m,key,low,high,mid;
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++)
		scanf("%d",&N[i]);
	for (int j=0;j<m;j++)
	{
		scanf("%d",&key);
		low=0;
		high=n-1;
		mid=(low+high)/2;
		int flag=0;
		while(low<=high)
		{
			if (key==N[mid])
			{
				printf("%d\n",mid);
				flag=1;
				break;
			}
			else if(key>N[mid])
			{
				low=mid+1;
				mid=(low+high)/2;
			}
			else if(key<N[mid])
			{
				high=mid-1;
				mid=(low+high)/2;
			}
		}
		if (flag==0)
			printf("%d\n",-1);
	}
	return 0;
}