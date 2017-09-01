#include <iostream>
using namespace std;

int Hash[101];

int main()
{
	int n;
	
	while (cin>>n)
	{
		for (int i=1;i<=100;i++)
			Hash[i]=0;
		
		for (int i=1;i<=n;i++)
		{
			int p;
			cin>>p;
			
			int flag=0;
			for (int i=1;i<=96;i=i+5)
			{
				int temp=Hash[i]+Hash[i+1]+Hash[i+2]+Hash[i+3]+Hash[i+4];
				if (5-temp>=p)
				{
					flag=1;
					for (int k=i;k<=i+4;k++)
					{
						if (Hash[k]==0)
						{
							for (int j=1;j<p;j++)
							{
								Hash[k+j-1]=1;
								cout<<k+j-1<<" ";
							}
							Hash[k+p-1]=1;
							cout<<k+p-1<<endl;
							break;
						}
					}
					break;
				}
			}
			
			if (flag==0)
			{
				int num=1;
				for (int i=1;i<=100 && num<p ;i++)
				{
					if (Hash[i]==0)
					{
						cout<<i<<" ";
						Hash[i]=1;
						num++;
					}
				}
				for (int i=1;num==p;i++)
				{
					if (Hash[i]==0)
					{
						cout<<i<<endl;
						Hash[i]=1;
						num++;
					}
				}
			}
		}
		
	}
	return 0;
}