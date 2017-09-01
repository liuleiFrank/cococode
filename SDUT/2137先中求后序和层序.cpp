#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct BiTNode
{
	char data;
	struct BiTNode* lc;
	struct BiTNode* rc;
}BiTNode;

char str1[51];
char str2[51];
BiTNode* queue[100];

BiTNode* creat(int s1,int t1,int s2,int t2)
{
	char key=str1[s1];
	BiTNode* S=(BiTNode*)malloc (sizeof(BiTNode));
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

void LevelOrder(BiTNode* T)
{
	int front=-1;
	int rear=-1;
	queue[++rear]=T;
	while (front!=rear)
	{
		front++;
		printf("%c",queue[front]->data);
		if (queue[front]->lc!=NULL)
			queue[++rear]=queue[front]->lc;
		if (queue[front]->rc!=NULL)
			queue[++rear]=queue[front]->rc;
	}
}

int main()
{
	int t;

	scanf("%d",&t);
	for (int i=0;i<t;i++)
	{
		scanf("%s",&str1);
		scanf("%s",&str2);
		int n1=strlen(str1);
		int n2=strlen(str2);
		BiTNode* T=creat(0,n1-1,0,n2-1);
		PostOrder(T);
		printf("\n");
		LevelOrder(T);
		printf("\n");
	}
	return 0;
}