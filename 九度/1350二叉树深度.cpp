//========================================================	1350	�����������
#include<stdio.h>
#include<stdlib.h>

int getdepth(int T[12][3],int tar)
{
	int count , ldepth ,rdepth ;
	if (T[tar-1][1]==-1 && T[tar-1][2]==-1)//����ڵ�û�к��ӣ����Ϊ1
		count=1;
	else
	{
		if (T[tar-1][1]!=-1)
			ldepth=getdepth(T,T[tar-1][1]);//�ڵ������������
		else
			ldepth=0;//û�������������Ϊ0

		if (T[tar-1][2]!=-1)
			rdepth=getdepth(T,T[tar-1][2]);//�ڵ������������
		else 
			rdepth=0;//û�������������Ϊ0

		//�ڵ����� = max{��������ȣ����������}+ 1
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