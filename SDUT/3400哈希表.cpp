#include <stdio.h>
long int Hash[101];
int main()
{
	long int N;
	while (scanf("%ld",&N)!=EOF)
	{
		for (int i=0;i<=100;i++)
			Hash[i]=0;
		for (int kk=1;kk<=N;kk++)
		{
			int key;
			scanf("%d",&key);
			if (key>100)
				key=100;
			Hash[key]++;
		}

		for (int i=0;i<=100;i++)
			if (Hash[i]!=0)
				printf("%d %d\n",i,Hash[i]);
	}
	return 0;
}