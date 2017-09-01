//题目1156：谁是你的潜在朋友
#include<stdio.h>
int main()
{
	int N,M;
	int Book[201];
	int P[201];
	while(scanf("%d%d",&N,&M)!=EOF)
	{
		for (int i=1;i<=M;i++)
			Book[i]=-1;
		for (int i=1;i<=N;i++)
		{
			scanf("%d",&P[i]);
			Book[P[i]]++;
		}
		for (int i=1;i<=N;i++)
		{
			if (Book[P[i]]==-1 || Book[P[i]]==0)
				printf("BeiJu\n");
			else
				printf("%d\n",Book[P[i]]);
		}
	}
	return 0;
}
