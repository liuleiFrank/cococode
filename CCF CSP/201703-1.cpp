#include <iostream>
using namespace std;

int A[1001];

int main()
{
	int n,k;
	
	while(cin>>n>>k)
	{
		for (int i=1;i<=n;i++)
			cin>>A[i];
		
		int num=0;
		int j;
		
		for (int i=1;i<=n;i=i+j)
		{
			int sum=0;
			j=0;
			
			while ( sum<k && i+j<=n )
			{
				sum=sum+A[i+j];
				j++;
			}
			
			num++;
		}
		
		cout<<num<<endl;
	}

	return 0;
}