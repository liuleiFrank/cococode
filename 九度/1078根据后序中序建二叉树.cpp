#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char str1[30];
char str2[30];

typedef struct BiTNode
{
	char data;
	struct BiTNode* lc;
	struct BiTNode* rc;
}BiTNode;

void PreOrder(BiTNode* T)
{
	if (T!=NULL)
	{
		printf("%c",T->data);
		PreOrder(T->lc);
		PreOrder(T->rc);
	}
}

BiTNode* Bulid(int s1,int t1,int s2,int t2)
{
	char key=str1[t1];
	BiTNode* S=(BiTNode*)malloc(sizeof(BiTNode));
	S->data=key;

	int i,flag;
	for (i=s2;i<=t2;i++)
	{
		if (str2[i]==key)
		{
			flag=i;
			break;
		}
	}

	if (flag!=s2)
		S->lc=Bulid(s1,s1+flag-1-s2,s2,flag-1);
	else 
		S->lc=NULL;

	if (flag!=t2)
		S->rc=Bulid(s1+flag-s2,t1-1,flag+1,t2);
	else
		S->rc=NULL;

	return S;
}

int main()
{
	while(scanf("%s%s",&str1,&str2)!=EOF)
	{
		int a=strlen(str1);
		int b=strlen(str2);
		BiTNode* T=Bulid(0,a-1,0,b-1);
		PreOrder(T);
		printf("\n");
	}
	return 0;
}
