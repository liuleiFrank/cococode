//��Ŀ1112�����ص��� �����\����������LIS 
//����������ж�Ӧ���������ض��ٵ���
//����������ж�Ӧ������Ҫ��������ϵͳ���ܰ������������е���
#include<stdio.h>
int main()
{
	int k;
	int A[1001];
	int L[1001];
	while(scanf("%d",&k)!=EOF)
	{
		for (int i=0;i<k;i++)
		{
			scanf("%d",&A[i]);
			L[i]=1;
		}

		for (int j=0;j<k;j++)
			for (int i=0;i<j;i++)
				if (A[i]>=A[j] && L[j]<L[i]+1)
					L[j]=L[i]+1;

		int max=1;
		for (int i=0;i<k;i++)
			if(L[i]>max)
				max=L[i];
		printf("%d\n",max);

	}
	return 0;
}

