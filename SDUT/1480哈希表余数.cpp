#include <stdio.h>
#define N 1000001
long int hash[N];//�洢��ֵ
int hashL[N];//�洢����

int main()
{
	int n,i,j;
	while (scanf("%d",&n)!=EOF)
	{
		for (i=0;i<N;i++)
		{
			hash[i]=-1;
			hashL[i]=0;
		}

		for (i=0;i<n;i++)
		{
			long int key;
			scanf("%ld",&key);

			int yu=key % N;

			//���գ�ֱ�Ӵ���
			if (hash[yu]==-1)
			{
				hash[yu]=key;
				hashL[yu]++;
			}
			//�����գ������ҿյ� �� ��ͬ��ֵ
			else 
			{
				for (j=yu; ;j++)
				{
					if(j>N)
						j=0;//ѭ�������Ҵ洢�ĵط�
					if (hash[j]==-1)
					{
						hash[j]=key;
						hashL[j]++;
						break;
					}
					else if (hash[j]==key)
					{
						hashL[j]++;
						break;
					}
				}
			}
		}

		int max=0;
		long int minvalue=100000000;
		for (i=0;i<=N;i++)
		{
			if ( hashL[i]>max || ( hashL[i]==max && hash[i]<minvalue ) )
			{
				max=hashL[i];
				minvalue=hash[i];
			}
		}
		printf("%ld %d\n",minvalue,max);
	}
	return 0;
}