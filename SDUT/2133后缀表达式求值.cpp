#include <stdio.h>
#include <string.h>

int main()
{
	int stack[1001];
	char str[1001];
	while (scanf("%s",&str)!=EOF)
	{
		int n=strlen(str);
		int top=-1;
		for (int i=0;i<n;i++)
		{
			if (str[i]=='+')
			{
				int temp=stack[top]+stack[top-1];
				stack[--top]=temp;
			}
			else if (str[i]=='-')
			{
				int temp=stack[top-1]-stack[top];
				stack[--top]=temp;
			}
			else if (str[i]=='*')
			{
				int temp=stack[top-1]*stack[top];
				stack[--top]=temp;
			}
			else if (str[i]=='/')
			{
				int temp=stack[top-1]/stack[top];
				stack[--top]=temp;
			}
			else if (str[i]=='#')
				break;
			else 
				stack[++top]=(int) str[i]-'0';
		}
		printf("%d\n",stack[top]);
	}

	return 0;
}