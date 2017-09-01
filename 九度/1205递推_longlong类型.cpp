#include<stdio.h>
long long  NN[91];
int main()
{
	int N,ans;
	NN[1]=1;
	NN[2]=2;
	for (int i=3;i<=90;i++)
			NN[i]=NN[i-1]+NN[i-2];
	while(scanf("%d",&N)!=EOF)
		printf("%lld\n",NN[N]);
	return 0;
}

/*
#include <stdio.h>
int main()
{
	int N,i;
	__int64 A[91];
	A[1]=1;
	A[2]=2;
	for (i=3;i<=90;i++)
		A[i]=A[i-1]+A[i-2];
	while(scanf("%d",&N)!=EOF)
		printf("%I64d\n",A[N]);
	return 0;
}
*/

