//ÌâÄ¿1036£ºOld Bill  Ã¶¾Ù
#include<stdio.h>
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		int x,y;
		int X,Y,W=0;
		for (int x=1;x<=9;x++)
		{
			for (int y=0;y<=9;y++)
			{
				int w=10000*x+1000*a+100*b+10*c+y;
				if ((w %n)==0)
				{
					X=x;
					Y=y;
					W=w;
				}
			}
		}
		if (W==0)
			printf("%d\n",0);
		else
			printf("%d %d %d\n",X,Y,W/n);
	}
	return 0;
}
