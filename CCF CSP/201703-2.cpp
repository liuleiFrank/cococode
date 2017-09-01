#include <iostream>
using namespace std;

int A[1001];

int main()
{
	int n,m;
	while (cin>>n>>m)
	{
		for (int i=1;i<=n;i++)
			A[i]=i;
		
		for (int i=1;i<=m;i++)
		{
			int p,q;
			cin>>p>>q;
			
			int flag;
			for (int j=1;j<=n;j++)
			{
				if (A[j]==p)
				{
					flag=j;
					break;
				}
			}
			
			int temp=p;
			if (q>0)
			{
				for (int j=0;j<=q-1;j++)
					A[flag+j]=A[flag+j+1];
				A[flag+q]=temp;
			}
			else if (q<0)
			{
				for (int j=0;j<=-q-1;j++)
					A[flag-j]=A[flag-j-1];
				A[flag+q]=temp;
			}
		}
		
		for (int i=1;i<n;i++)
			cout<<A[i]<<" ";
		cout<<A[n]<<endl;
		
	}
	
	return 0;
}