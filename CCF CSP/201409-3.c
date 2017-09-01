#include <stdio.h>
#include <string.h>

int main()
{
	char S[120];
	while (scanf("%s",S)!=EOF)
	{
		int flag;
		int n;
		scanf("%d %d",&flag,&n);

		for (int i=1;i<=n;i++)
		{
			char str[120];
			scanf("%s",str);

			char T[120];
			strcpy(T,str);

			if (flag==0)
			{
			    strlwr(S);
				strlwr(str);
			}
			
			if (strstr(str,S)!=NULL)
				printf("%s\n",T);
		}

	}
	return 0;
}