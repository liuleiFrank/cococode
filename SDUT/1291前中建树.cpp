#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char str1[1001];
char str2[1001];

typedef struct BiTNode
{
	char data;
	struct BiTNode* lc;
	struct BiTNode* rc;
}BiTNode;

BiTNode* creat(int s1,int t1,int s2,int t2)
{
	char key=str1[s1];
	BiTNode* S=(BiTNode*)malloc(sizeof(BiTNode));
	S->data=key;
	S->lc=NULL;
	S->rc=NULL;

	int flag;
	for (int i=s2;i<=t2;i++)
	{
		if (str2[i]==key)
		{
			flag=i;
			break;
		}
	}

	if (flag!=s2)
		S->lc=creat(s1+1,s1+flag-s2,s2,flag-1);
	if (flag!=t2)
		S->rc=creat(s1+flag-s2+1,t1,flag+1,t2);
	return S;
}

void PostOrder(BiTNode* T)
{
	if (T!=NULL)
	{
		PostOrder(T->lc);
		PostOrder(T->rc);
		printf("%c",T->data);
	}
}

int main()
{
	while (scanf("%s %s",&str1,&str2)!=EOF)
	{
		int a=strlen(str1);
		int b=strlen(str2);
		BiTNode* T=creat(0,a-1,0,b-1);
		PostOrder(T);
		printf("\n");
	}
	return 0;
}
