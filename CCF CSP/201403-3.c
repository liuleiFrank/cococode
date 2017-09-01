#include <stdio.h>
#include <string.h>

typedef struct ML
{
	int f;
	char zf;
	char zfc[260];
}ML;

int func(char string[60],char c)
{
	int n=strlen(string);
	int flag=0;
	for (int i=0;i<n;i++)
	{
		if (string[i]==c && string[i+1]==':')
		{
			flag=1;
			return 1;
		}
		else if (string[i]==c && string[i+1]!=':')
		{
			flag=1;
			return 0;
		}
	}
	if (flag==0)
		return -1;
}

int main()
{
	char str[60];
	while (scanf("%s",str)!=EOF)
	{
		
		int N;
		scanf("%d",&N);

		char nu;scanf("%c",&nu);//吸收空格

		char S[250];
		for (int k=1;k<=N;k++)
		{
			ML myml[26];//参数和选项
			for (int i=0;i<26;i++)
				myml[i].f=0;//未出现为0

			gets(S);
			int n=strlen(S);

			for (int i=0;i<n;i++)
			{
				if (S[i]=='-')
				{
					char M=S[i+1];

					if (func(str,M)==-1)//非法选项
						break;

					if (func(str,M)==0)//合法选项
					{
						if (S[i+3]!='-')//非法参数
							break;
						myml[M-'a'].zf=M;
						myml[M-'a'].f=1;//出现，无参数为1
					}

					if (func(str,M)==1)//合法选项，读取参数
					{
						
						char cs[260];
						int j=i+3;
						int num=-1;
						while(S[j]!=' '&& S[j]!='\0')
							cs[++num]=S[j++];
						cs[++num]='\0';
						
						strcpy(myml[M-'a'].zfc,cs);

						myml[M-'a'].zf=M;
						myml[M-'a'].f=2;//出现，有参数为2
					}
				}
			}
			printf("Case %d: ",k);
			for (int i=0;i<26;i++)
			{
				if (myml[i].f==0)
					continue;
				else if (myml[i].f==1)
					printf("-%c ",myml[i].zf);
				else if (myml[i].f==2)
					printf("-%c %s ",myml[i].zf,myml[i].zfc);
			}
			printf("\n");
		}
	}
	return 0;
}