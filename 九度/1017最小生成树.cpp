//题目1017：还是畅通工程
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

typedef struct DD{
	int a;
	int b;
	int v;
}DD;

DD D[5000];

int main()
{
	int N;
	while(scanf("%d",&N) && N!=0)
	{
		for (int i=0;i<N;i++)
			Tree[i]=-1;

		int M=N*(N-1)/2;

		for (int i=0; i< M ;i++)
			scanf("%d%d%d",&D[i].a,&D[i].b,&D[i].v);

		for(int i=M-1;i>0;i--)
			for (int j=0;j<i;j++)
				if (D[j].v>D[j+1].v)
				{
					int temp0=D[j].a;
					D[j].a=D[j+1].a;
					D[j+1].a=temp0;

					int temp1=D[j].b;
					D[j].b=D[j+1].b;
					D[j+1].b=temp1;

					int temp2=D[j].v;
					D[j].v=D[j+1].v;
					D[j+1].v=temp2;
				}

		int count =0;
		int ans=0;
		for (int i=0;count!=N-1;i++)
		{
			int ra,rb;
			ra=findRoot(D[i].a-1);
			rb=findRoot(D[i].b-1);
			if (ra!=rb)
			{
				Tree[ra]=rb;
				ans=ans+D[i].v;
				count++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}