#include <stdio.h>

int queue[100001];

int main()
{
	int m,n,key;
	while (scanf("%d",&m)!=EOF)
	{
		int front=-1;
		int rear=-1;
		for (int i=0;i<m;i++)
		{
			scanf("%d",&key);
			queue[++rear]=key;
		}

		scanf("%d",&n);

		for (int i=0;i<n;i++)
		{
			char str[10];
			int num;
			scanf("%s",&str);

			if ( str[0]=='J')
			{
				scanf("%d",&num);
				queue[++rear]=num;
			}

			else if (str[0]=='A')
			{
				scanf("%d",&num);
				printf("%d\n",queue[front + num]);
			}

			else if (str[0]=='L'&&str[2]=='A')
			{
				scanf("%d",&num);
				for (int j=front+num+1;j<=rear;j++)
					queue[j-1]=queue[j];
				rear--;
			}

			else if (str[0]=='L'&&str[2]=='N')
			{
				printf("%d\n",rear-front);
			}

			else if (str[0]=='F')
			{
				scanf("%d",&num);
				front=front+num;
			}
		}
	}
	return 0;
}