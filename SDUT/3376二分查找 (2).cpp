#include <stdio.h>
int A[1000001];
int n,m;
int find(int key)
{
	int low=0;
	int high=n-1;
	while (low<=high)
	{
		int mid=(low+high)/2;
		if (A[mid]==key)
			return mid;
		else if (A[mid]>key)
			high=mid-1;
		else if (A[mid]<key)
			low=mid+1;
	}
	return -1;
}

int main()
{

	while (scanf("%d %d",&n,&m)!=EOF)
	{
		for (int i=0;i<n;i++)
			scanf("%d",&A[i]);
		for (int i=1;i<=m;i++)
		{
			int key;
			scanf("%d",&key);
			int ans=find(key);
			printf("%d\n",ans);
		}
	}
	return 0;
}