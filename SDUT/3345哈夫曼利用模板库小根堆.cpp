#include <stdio.h>
#include <queue>
#include <string.h>
#include <functional>

using namespace std;

priority_queue < int,vector<int>,greater<int> > Q;

int num[200];

int main()
{
	char str[1001];
	while (scanf("%s",&str)!=EOF)
	{
		int n=strlen(str);
		for (int i=0;i<200;i++)
			num[i]=0;
		for (int i=0;i<n;i++)
			num[(int)str[i]]++;
		while (Q.empty()!=1)
			Q.pop();
		int count=0;
		for (int i=0;i<200;i++)
		{
			if (num[i]!=0)
			{
				Q.push(num[i]);
				count++;
			}
		}

		int sum=0;
		for (int kk=1;kk<=count-1;kk++)
		{
			int min1=Q.top();
			Q.pop();
			int min2=Q.top();
			Q.pop();
			sum=sum+min1+min2;
			Q.push(min1+min2);
		}
		double b=8*(double)n/(double)sum;
		printf("%d %d %.1lf\n",8*n,sum,b);
	}
	return 0;
}