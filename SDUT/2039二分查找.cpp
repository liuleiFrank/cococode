#include <stdio.h>

int A[100001];

int main()
{
	int n;
	while (scanf("%d",&n)!=EOF)
	{
		for (int i=0;i<n;i++)
			scanf("%d",&A[i]);

		int key;
		scanf("%d",&key);

		int low=0;
		int high=n-1;
		int mid;
		int flag=0;
		while (low<=high)
		{
			mid=(low + high)/2;
			if (A[mid]==key)
			{
				printf("YES\n");
				flag=1;
				break;
			}
			else if (A[mid]>key)
				high=mid-1;
			else if (A[mid]<key)
				low=mid+1;
		}
		if (flag==0)
			printf("NO\n");
	}
	return 0;
}