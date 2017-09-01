#include <stdio.h>

int stack[1000001];

int main()
{
	int a;
	int R;
	while( scanf("%d %d",&a,&R)!=EOF)
	{
		if (a==0)
		{
			printf("%d\n",0);
			continue;
		}

		int top=-1;
		while (a!=0)
		{
			stack[++top]=a%R;
			a=a/R;
		}

		while (top!=-1)
			printf("%d",stack[top--]);
		printf("\n");
	}
	return 0;
}