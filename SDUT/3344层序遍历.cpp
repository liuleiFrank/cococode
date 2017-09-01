#include<stdio.h>
#include<stdlib.h>

typedef struct BiTNode{
	char data;
	struct BiTNode* lc;
	struct BiTNode* rc;
}BiTNode;

void CreatTree(BiTNode* &T,char str[100],int &num)
{
	if (str[num]==',')
		T=NULL;
	else
	{
		BiTNode* S=(BiTNode*)malloc(sizeof(BiTNode));
		S->data=str[num];
		T=S;
		CreatTree(T->lc,str,++num);
		CreatTree(T->rc,str,++num);
	}
}

BiTNode* queue[100];

void COrder(BiTNode* T)
{
	if(T!=NULL) //²âÊÔÓÃÀýÓÐ¿ÕÊ÷£¡£¡£¡
	{
		int nu=-1;
		int flag=-1;
		queue[++nu]=T;
		while(flag!=nu)
		{
			printf("%c",queue[++flag]->data);
			if (queue[flag]->lc!=NULL)
				queue[++nu]=queue[flag]->lc;
			if (queue[flag]->rc!=NULL)
				queue[++nu]=queue[flag]->rc;
		}
	}
}

char str[100];

int main()
{
	int t;
	scanf("%d",&t);
	for (int i=0;i<t;i++)
	{
		scanf("%s",str);
		int num=0;
		BiTNode* T;
		CreatTree(T,str,num);
		COrder(T);
		printf("\n");
	}
	return 0;
}