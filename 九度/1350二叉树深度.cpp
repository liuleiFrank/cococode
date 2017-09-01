//========================================================	1350	二叉树的深度
#include<stdio.h>
#include<stdlib.h>

int getdepth(int T[12][3],int tar)
{
	int count , ldepth ,rdepth ;
	if (T[tar-1][1]==-1 && T[tar-1][2]==-1)//如果节点没有孩子，深度为1
		count=1;
	else
	{
		if (T[tar-1][1]!=-1)
			ldepth=getdepth(T,T[tar-1][1]);//节点左子树的深度
		else
			ldepth=0;//没有左子树，深度为0

		if (T[tar-1][2]!=-1)
			rdepth=getdepth(T,T[tar-1][2]);//节点右子树的深度
		else 
			rdepth=0;//没有右子树，深度为0

		//节点的深度 = max{左子树深度，右子树深度}+ 1
		if ( ldepth >= rdepth )
			count=ldepth+1;
		else
			count=rdepth+1;
	}
	return count;
}

int main()
{
	int T[12][3];
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		T[i][0]=i+1;
		scanf("%d %d",&T[i][1],&T[i][2]);
	}
	int count=getdepth(T,T[0][0]);
	printf("%d\n",count);
	return 0;
}