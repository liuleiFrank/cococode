// 题目1144：Freckles
#include<stdio.h>
#include<math.h> // math.h是C标准函数库中的头文件。提供用于常用高级数学运算的运算函数。
#include<stdlib.h>

int Tree[101];

struct xy{
	double x;
	double y;
};
struct xy D[100];

struct dis{
	int a;
	int b;
	double dist;
};
struct dis DIS[5000];

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

int cmp(const void* a,const void*b)
{
	return (*(struct dis*)a).dist <  (*(struct dis*)b).dist ? -1 :1;
}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		for (int i=0;i<n;i++)
		{
			Tree[i]=-1;
			scanf("%lf %lf",&D[i].x,&D[i].y);
		}

		int num=-1;
		for (int i=0;i<n-1;i++)
			for (int j=i+1;j<n;j++)
			{
				++num;
				DIS[num].a=i;
				DIS[num].b=j;
				DIS[num].dist=sqrt(   (D[i].x-D[j].x)*(D[i].x-D[j].x) +  (D[i].y-D[j].y)*(D[i].y-D[j].y) );
			}

		qsort(DIS,num+1,sizeof(DIS[0]),cmp);
		//冒泡排序
		/*
		for (int i=num;i>0;i--)
			for (int j=0;j<i;j++)
				if (DIS[j].dist > DIS[j+1].dist)
				{
					int temp0=DIS[j].a;
					DIS[j].a=DIS[j+1].a;
					DIS[j+1].a=temp0;

					int temp1=DIS[j].b;
					DIS[j].b=DIS[j+1].b;
					DIS[j+1].b=temp1;

					double temp2=DIS[j].dist;
					DIS[j].dist=DIS[j+1].dist;
					DIS[j+1].dist=temp2;
				}
		*/

		double ans=0;
		int count=1;
		for (int i=0;count<=n-1;i++)
		{
			int ra=findRoot(DIS[i].a);
			int rb=findRoot(DIS[i].b);
			if (ra!=rb)
			{
				Tree[ra]=rb;
				ans=ans+DIS[i].dist;
				count++;
			}
		}
		printf("%.2lf\n",ans);
	}
	return 0;
}