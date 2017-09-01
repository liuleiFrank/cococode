//===================================1107	搬水果	2011年吉林大学计算机研究生机试真题
#include<stdio.h>
#include<queue>
#include <functional>
using namespace std;
priority_queue<int , vector<int> , greater<int> > Q;

int main()
{
	int n;
	while(scanf("%d",&n))
	{
		if (n==0)
			return 0;
		while (Q.empty()==false)
			Q.pop();
		for (int i=0; i<n ; i++)
		{
			int a;
			scanf("%d",&a);
			Q.push(a);
		}
		int ans=0;
		for (int i=0; i<n-1;i++)
		{
			int top0=Q.top();
			Q.pop();
			int top1=Q.top();
			Q.pop();
			ans=ans+top0+top1;
			Q.push(top0+top1);
		}
		printf("%d\n",ans);
	}
	return 0;
}