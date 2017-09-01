#include <stdio.h>

typedef struct window
{
	int xmin,ymin;
	int xmax,ymax;
	int p;
}window;

window WIN[11];

int main()
{
	int N,M;
	while (scanf("%d %d",&N,&M)!=EOF)
	{
		for (int i=1;i<=N;i++)
		{
			scanf("%d %d %d %d",&WIN[i].xmin,&WIN[i].ymin,&WIN[i].xmax,&WIN[i].ymax);
			WIN[i].p=i;
		}

		for (int i=1;i<=M;i++)
		{
			int x,y;
			scanf("%d %d",&x,&y);

			int flag=0;
			int p2=0;
			for (int j=1;j<=N;j++)
			{
				if (x>=WIN[j].xmin && y>=WIN[j].ymin && x<=WIN[j].xmax && y<=WIN[j].ymax)
				{
					if (WIN[j].p>p2)
					{
						flag=j;
						p2=WIN[j].p;
					}
				}
			}

			for (int j=1;j<=N;j++)
			{
				if (WIN[j].p > p2)
					WIN[j].p--;
			}
			WIN[flag].p=N;

			if (flag==0)
				printf("IGNORED\n");
			else 
				printf("%d\n",flag);
		}
	}
	return 0;
}