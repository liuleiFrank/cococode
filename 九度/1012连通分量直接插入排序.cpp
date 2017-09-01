#include<stdio.h>

int D[5001][3];
int Root[101];

int findRoot(int x)
{
	if(Root[x]==-1)
		return x;
	else
	{
		int temp=findRoot(Root[x]);
		Root[x]=temp;
		return temp;
	}
}

int main()
{
	int N;
	while(scanf("%d",&N)!=EOF && N!=0)
	{
		for (int i=1;i<=N;i++)
			Root[i]=-1;

		int M=(N-1)*N/2;
		//Ö±½Ó²åÈëÅÅÐò
		scanf("%d %d %d",&D[1][0],&D[1][1],&D[1][2]);
		for (int i=2;i<=M;i++)
		{
			scanf("%d %d %d",&D[0][0],&D[0][1],&D[0][2]);
			int j;
			for (j=i-1;D[j][2]>D[0][2];j--)
			{
				D[j+1][2]=D[j][2];
				D[j+1][0]=D[j][0];
				D[j+1][1]=D[j][1];
			}
			D[j+1][2]=D[0][2];
			D[j+1][0]=D[0][0];
			D[j+1][1]=D[0][1];
		}

		
		int count=0;
		int cost=0;
		for (int i=1;count!=N-1;i++)
		{
			int Ra=findRoot(D[i][0]);
			int Rb=findRoot(D[i][1]);
			if (Ra!=Rb)
			{
				Root[Ra]=Rb;
				cost=cost+D[i][2];
				count++;
			}
		}
		printf("%d\n",cost);
	}
	return 0;
}