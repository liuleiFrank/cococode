#include<stdio.h>
int a[51][3];
int b[51][3];
int count[10001];
int book[10001];

int main()
{
	int mu,nu,tu;
	while(scanf("%d %d %d",&mu,&nu,&tu)!=EOF)
	{
		for (int i=1;i<=nu;i++)
			count[i]=0;

		for (int kk=1;kk<=tu;kk++)
		{
			scanf("%d %d %d",&a[kk][0],&a[kk][1],&a[kk][2]);
			count[ a[kk][1] ]++;
		}

		book[1]=1;
		for (int i=2;i<=nu;i++)
			book[i]=book[i-1]+count[i-1];

		for (int kk=1;kk<=tu;kk++)
		{
			int flag=a[kk][1];
			int flag2=book[flag];
			b[flag2][0]=a[kk][1];
			b[flag2][1]=a[kk][0];
			b[flag2][2]=a[kk][2];
			book[flag]++;
		}

		for (int kk=1;kk<=tu;kk++)
			printf("%d %d %d\n",b[kk][0],b[kk][1],b[kk][2]);
	}
	return 0;
}