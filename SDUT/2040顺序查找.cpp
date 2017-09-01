#include <stdio.h>
int A[1001];
int main()
{
	int n;
	while (scanf("%d",&n)!=EOF)
	{
		for (int i=1;i<=n;i++)
			scanf("%d",&A[i]);

		int key;
		scanf("%d",&key);

		int flag=0;
		
		for (int i=n;i>0;i--)
		{
			if (A[i]==key)
			{
				printf("YES\n");
				flag=1;
				break;
			}
		}
		
		if (flag==0)
			printf("NO\n");
	}

	return 0;
}