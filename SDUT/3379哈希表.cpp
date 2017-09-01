#include<stdio.h>
int Hash[5000];
int NN[1001];
int main()
{
	int N,p,key;
	while(scanf("%d %d",&N,&p)!=EOF)
	{
		for (int i=0;i<p;i++)
			Hash[i]=-1;

		for (int i=0;i<N;i++)
		{
			scanf("%d",&key);
			int a=key % p;
			while(Hash[a]!=-1 && Hash[a]!=key)
			{
				if (a<p-1)
					a++;
				else if (a==p-1)
					a=0;
			}
			Hash[a]=key;
			NN[i]=a;
		}

		for (int i=0;i<N-1;i++)
			printf("%d ",NN[i]);
		printf("%d",NN[N-1]);
		printf("\n");
	}
	return 0;
}
