#include <stdio.h>

int Hash[1001];

int main()
{
	int N,a;
	while (scanf("%d",&N)!=EOF)
	{
		for (int i=1;i<=1000;i++)
			Hash[i]=0;
		for (int i=1;i<=N;i++)
		{
			scanf("%d",&a);
			if (a<0)
				a=-1*a;
			Hash[a]++;
		}
		int num=0;
		for (int i=1;i<=1000;i++)
		{
			if (Hash[i]==2)
				num++;
		}
		printf("%d\n",num);
	}


	return 0;
}