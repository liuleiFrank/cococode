#include<stdio.h>
#include<stdlib.h>

char str1[51],str2[51];

typedef struct BiTNode{
	char data;
	struct BiTNode* lc;
	struct BiTNode* rc;
}BiTNode;

BiTNode* Build(int s1,int e1,int s2,int e2)
{
	BiTNode* r=(BiTNode*) malloc (sizeof(BiTNode));
	r->data=str1[s1];

	int flag;
	for (int i=0;i<=e2;i++)
	{
		if(str2[i]==str1[s1])
		{
		    flag=i;
			break;
		}
	}

	if (flag!=s2)
		r->lc=Build(s1+1,s1+(flag-s2),s2,flag-1);
	else
		r->lc=NULL;

	if (flag!=e2)
		r->rc=Build(s1+(flag-s2)+1,e1,flag+1,e2);
	else
		r->rc=NULL;

	return r;
}


int getdepth(BiTNode* T)
{
	int depth;
	if (T==NULL)
		depth=0;
	else
	{
		int  lcdepth=0,rcdepth=0;

		if(T->lc!=NULL)
			lcdepth=getdepth(T->lc);
		if(T->rc!=NULL)
			rcdepth=getdepth(T->rc);

		if (lcdepth>rcdepth)
			depth=lcdepth+1;
		else
			depth=rcdepth+1;
	}
	return depth;
}

int main()
{
	int N;
	while(scanf("%d",&N)!=EOF)
	{
		scanf("%s%s",str1,str2);
		BiTNode* T=Build(0,N-1,0,N-1);

		int d=getdepth(T);
		printf("%d\n",d);
	}
	return 0;
}
