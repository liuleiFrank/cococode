#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char str1[30],str2[30];

typedef struct Node{
	struct Node* lc;
	struct Node* rc;
	char c;
}Node;

void postorder(Node *T)
{
	if(T)
	{
		postorder(T->lc);
		postorder(T->rc);
		printf("%c",T->c);
	}
}

Node * build(int s1,int e1,int s2,int e2)
{
	Node * ret=(Node *) malloc (sizeof(Node));
	ret->c=str1[s1];

	int dx;
	for (int i=s2;i<=e2;i++)
		if (str2[i]==str1[s1])
		{
			dx=i;
			break;
		}

	if (dx!=s2)
		ret->lc=build(s1+1,s1+(dx-s2),s2,dx-1);
	else
		ret->lc=NULL;

	if (dx!=e2)
		ret->rc=build(s1+(dx-s2)+1,e1,dx+1,e2);
	else 
		ret->rc=NULL;

	return ret;
}

int main()
{
	while(scanf("%s%s",str1,str2)!=EOF)
	{
		int a=strlen(str1);
		int b=strlen(str2);
		Node * T=build(0,a-1,0,b-1);
		postorder(T);
		printf("\n");
	}
	return 0;
}
