#include <stdio.h>
#include <string.h>

char stack[101];

int main()
{
	char str[101];
	while (gets(str)!=NULL)
	{
		int top=-1;
		int flag=0;
		int n=strlen(str);
		for (int i=0;i<n;i++)
		{
			if ( str[i]=='(' || str[i]=='{' || str[i]=='[')
			{
				flag=1;
				stack[++top]=str[i];
			}
			else if ( (str[i]==')' || str[i]=='}' || str[i]==']') && top==-1)
			{
				flag=0;
				break;
			}
			else if ( str[i]==')' && stack[top]=='(')
				top--;
			else if ( str[i]==']' && stack[top]=='[')
				top--;
			else if ( str[i]=='}' && stack[top]=='{')
				top--;
		}
		if (top==-1 && flag==1)
			printf("yes\n");
		else
			printf("no\n");
	}
	
	return 0;
}