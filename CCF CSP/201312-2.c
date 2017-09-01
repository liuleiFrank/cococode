#include <stdio.h>
#include <string.h>

int main()
{
	char str[20];
	while (scanf("%s",str)!=EOF)
	{
		int i;
		int num=0;
		int count=0;
		for (i=0;i<=11;i++)
		{
			if (str[i]!='-')
			{
				int temp=str[i]-'0';
				num=num+(++count)*temp;
			}
		}
		
		int ans = num % 11;
		if (ans==str[12]-'0')
			printf("Right\n");
		else
		{
			for (i=0;i<=11;i++)
				printf("%c",str[i]);
			printf("%d\n",ans);	
		}
	}
	
	return 0;
}
