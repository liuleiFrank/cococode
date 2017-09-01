//===============================================1184	二叉树遍历	2002年华中科技大学计算机研究生机试真题  C++
/*
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<stdlib.h>

typedef struct BiTNode{
char a;
struct BiTNode* lchild;
struct BiTNode* rchild;
}BiTNode;

void CreateBiT(BiTNode* &T, char c[],int &i)
{
i++;
if (c[i]=='#')
T = NULL;
else
{
T=(BiTNode*)malloc(sizeof(BiTNode));
T->a=c[i];
CreateBiT(T->lchild,c,i);
CreateBiT(T->rchild,c,i);
}
}

void InOrder(BiTNode *  T)
{
if(T)
{
InOrder(T->lchild);
printf("%c ",T->a);
InOrder(T->rchild);
}
}

int main()
{
char c[120];
while(scanf("%s",&c)!=EOF)
{
int i=-1;
BiTNode * T;
CreateBiT(T,c,i);
InOrder(T);
printf("\n");
}
return 0;
}
*/

//===============================================1184	二叉树遍历	2002年华中科技大学计算机研究生机试真题  C

#include<stdio.h>
#include<stdlib.h> //malloc 需要

typedef struct BiTNode{
	char a;
	struct BiTNode* lchild;
	struct BiTNode* rchild;
}BiTNode;

void CreateBiT( BiTNode* (*T), char c[],int (*i))
{
	(*i)++;
	if (c[*i]=='#')
		*T = NULL;
	else
	{
		(*T)=(BiTNode*)malloc(sizeof(BiTNode));
		(*T)->a=c[*i];
		CreateBiT(  &((*T)->lchild),c,i);
		CreateBiT(  &((*T)->rchild),c,i);
	}
}

void InOrder(BiTNode * (*T) )
{
	if(*T)
	{
		InOrder( &((*T)->lchild) );
		printf("%c ",(*T)->a);
		InOrder( &((*T)->rchild) );
	}
}

int main()
{
	char c[120];
	while(scanf("%s",&c)!=EOF)
	{
		int i=-1;
		BiTNode * T;
		CreateBiT(&T,c,&i);
		InOrder(&T);
		printf("\n");
	}
	return 0;
}