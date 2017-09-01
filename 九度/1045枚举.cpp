//题目1045：百鸡问题  枚举
#include<stdio.h>

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		for (int x=0;x<=100;x++)
			for (int y=0;x+y<=100;y++)
			{
				int z=100-x-y;
				if (15*x+9*y+z<=3*n)
					printf("x=%d,y=%d,z=%d\n",x,y,z);
			}
	}
	return 0;
}
