//��Ŀ1018��ͳ��ͬ�ɼ�ѧ������ ��ϣ��
#include<stdio.h>
int main()
{
	int N,a,b;
	while(scanf("%d",&N)!=EOF && N!=0)
	{
		int hash[101]={0};
		for (int i=0;i<N;i++)
		{
			scanf("%d",&a);
			hash[a]++;
		}
		scanf("%d",&b);
		printf("%d\n",hash[b]);
	}
	return 0;
}
