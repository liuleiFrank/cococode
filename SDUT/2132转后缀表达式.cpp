#include<stdio.h>
#include<string.h>

char stack[1001];

int YX(char c)
{
	if (c=='*'||c=='/')
		return 1;
	else if (c=='+'||c=='-')
		return -1;
}

int main()
{
	char str[1001];
	while (scanf("%s",&str)!=EOF)
	{
		int n=strlen(str);
		int top=-1;
		for (int i=0;i<n;i++)
		{
			if (str[i]=='#')
				break;
			else if (str[i]=='(')
				stack[++top]=str[i];
			else if (str[i]==')')
			{
				while (stack[top]!='(')
					printf("%c",stack[top--]);
				top--;
			}
			else if (str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/')
			{
				while ( YX(stack[top]) > YX(str[i]) && top!=-1 && stack[top]!='(')
					printf("%c",stack[top--]);
				stack[++top]=str[i];
			}
			else 
				printf("%c",str[i]);
		}

		while (top!=-1)
			printf("%c",stack[top--]);
		printf("\n");
	}
	return 0;
}