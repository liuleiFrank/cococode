// 题目1448：Legal or Not 拓扑排序
#include <stdio.h>
#include <stdlib.h>

typedef struct ArcNode
{
	int data;
	struct ArcNode* nextarc;
}ArcNode;

typedef struct VNode
{
	int vex;
	struct ArcNode* firstarc;
}VNode;

int stack[101];
int IN[101];

int main()
{
	int N,M;
	VNode V[101];
	while (scanf("%d %d",&N,&M)!=EOF && N!=0)
	{
		for (int i=0;i<N;i++)
		{
			IN[i]=0;
			V[i].vex=i;
			V[i].firstarc=NULL;
		}

		for (int i=0;i<M;i++)
		{
			int x,y;
			scanf("%d %d",&x,&y);
			IN[y]++;
			
			ArcNode* S= (ArcNode*) malloc (sizeof (ArcNode));
			S->data=y;
			S->nextarc=V[x].firstarc;
			V[x].firstarc=S;
		}

		int top=-1;
		for (int i=0;i<N;i++)
		{
			if (IN[i]==0)
				stack[++top]=i;
		}

		int count=0;
		while (top!=-1)
		{
			int temp=stack[top];
			count++;
			top--;
			ArcNode* p=V[temp].firstarc;
			while (p!=NULL)
			{
				IN[p->data]--;
				if (IN[p->data]==0)
					stack[++top]=p->data;
				p=p->nextarc;
			}
		}

		if (count==N)
			printf ("YES\n");
		else 
			printf ("NO\n");

	}
	return 0;
}

//邻接矩阵总是WA
/*
#include <stdio.h>

int A[101][101];
int IN[101];
int stack[101];

int main()
{
	int N,M;
	while (scanf("%d %d",&N,&M)!=EOF && N!=0)
	{
		for (int i=0;i<N;i++)
		{
			IN[i]=0;
			for (int j=0;j<N;j++)
				A[i][j]=0;
		}

		for(int i=1;i<=M;i++)
		{
			int x,y;
			scanf("%d %d",&x,&y);
			if (A[x][y]==0)
				A[x][y]=1;
			IN[y]++;
		}

		int top=-1;
		int count=0;
		for (int i=0;i<N;i++)
		{
			if (IN[i]==0)
				stack[++top]=i;
		}

		while (top!=-1)
		{
			int temp=stack[top];
			top--;
			count++;

			for (int j=0;j<N;j++)
			{
				if (A[temp][j]==1)
				{
					IN[j]--;
					if (IN[j]==0)
						stack[++top]=j;
				}
			}

			for (int j=0;j<N;j++)
				A[temp][j]=0;
		}

		if (count==N)
			printf("YES\n");
		else 
			printf("NO\n");
	}
	return 0;
}
*/