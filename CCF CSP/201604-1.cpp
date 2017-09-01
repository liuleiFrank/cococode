#include <iostream>
using namespace std;

int A[1010];

int main()
{
	int n;
	while (cin>>n) 
	{
		for (int i=1;i<=n;i++)
			cin>>A[i];
			
		if (n==1 || n==2)
		{
			cout<<0<<endl;
			continue;
		}
		
		int num=0;
		for (int i=2;i<=n-1;i++)
		{
			if ( (A[i]-A[i-1]) * (A[i]-A[i+1]) >0 )
				num++;
		}
		cout<<num<<endl;
	}
	return 0;
}