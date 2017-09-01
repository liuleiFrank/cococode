#include <stdio.h>

int main()
{
	int n;
	int x0,x;
	int num;
	while (scanf("%d",&n)!=EOF)
	{
		num=0;
		int i;
		x0=-1;
		for (i=1;i<=n;i++)
		{
			scanf("%d",&x);
			if (x!=x0)
				num++;
			x0=x;
		}
		printf("%d\n",num);
	}

	return 0;
}



