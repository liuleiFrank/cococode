#include <stdio.h>
#include <string.h>

char stack[300];

int main()
{
	char str[300];
	while (scanf("%s",&str)!=EOF)
	{
		int top=-1;
		int n=strlen(str);
		for (int i=0;i<=n-1;i++)
		{
			char c=str[i];

			if (c=='@')
				top=-1;
			else if (c=='#')
			{
				if (top==-1)
					continue;
				else 
					top--;
			}
			else
				stack[++top]=c;
		}

		for (int i=0;i<=top;i++)
			printf("%c",stack[i]);
		printf("\n");
	}
	return 0;
}
