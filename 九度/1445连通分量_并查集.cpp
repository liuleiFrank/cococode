//题目：1445 How Many Tables
#include<stdio.h>
int Tree[1001];

int findRoot(int x)
{
	if (Tree[x]==-1)
		return x;
	else
	{
		int temp=findRoot(Tree[x]);
		Tree[x]=temp;
		return temp;
	}
}

int main()
{
	int T;
	scanf("%d",&T);
	for (int i=1;i<=T;i++)
	{
		int N,M;
		scanf("%d %d",&N,&M);

		for (int i=0;i<N;i++)
			Tree[i]=-1;

		for (int i=0;i<M;i++)
		{
			int A,B;
			scanf("%d %d",&A,&B);
			int rA,rB;
			rA=findRoot(A-1);
			rB=findRoot(B-1);
			if (rA!=rB)
				Tree[rA]=rB;
		}

		int count=0;
		for (int i=0;i<N;i++)
			if(Tree[i]==-1)
				count++;
		printf("%d\n",count);
	}
	return 0;
}
