#include <stdio.h>
#include <algorithm>

using namespace std;
int hash[10001];

typedef struct node
{
	int x;
	int num;
}node;

bool cmp(node a,node b)
{
	return a.num>b.num;
}

node N[1001];

int main()
{
	int n,a;
	while (scanf("%d",&n)!=EOF)
	{
		for (int i=0;i<=1000;i++)
			hash[i]=0;
			
		int num=0;
		
		for (int i=1;i<=n;i++)
		{
			scanf("%d",&a);
			hash[a]++;
		}
		for (int i=0;i<=1000;i++)
			if (hash[i]!=0)
				num++;
		for (int i=0;i<=1000;i++)
		{
			N[i].x=i;
			N[i].num=hash[i];
		}
		
		sort(N,N+1001,cmp);
		
		for (int i=0;i<num;i++)
			printf("%d %d\n",N[i].x,N[i].num);
	}
	return 0;
}



