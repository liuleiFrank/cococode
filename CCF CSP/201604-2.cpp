#include <iostream>
using namespace std;

int A[20][20];
int B[5][5];
int flag;

int main()
{
	for (int i=1;i<=20;i++)
		for (int j=1;j<=20;j++)
			A[i][j]=0;
			
	while (cin>>A[1][1])
	{
		for (int i=2;i<=10;i++)
			cin>>A[1][i];
		for (int i=2;i<=15;i++)
			for (int j=1;j<=10;j++)
				cin>>A[i][j];
		
		for (int i=1;i<=4;i++)
			for (int j=1;j<=4;j++)
				cin>>B[i][j];
				
		cin>>flag;
		
		
		
		int p=1;
		for (int i=1;i<=4;i++)
		{
			int sum=0;
			for (int j=1;j<=4;j++)
				sum=sum+B[i][j];
			if (sum>0)
				p=i;
		}
		
		int n;
		int temp;
		
		for (n=1;n<=12+4-p ;n++)
		{
			for (int i=1;i<=4;i++)
			{
				for (int j=1;j<=4;j++)
				{
					temp=B[i][j]+A[n+i-1][flag+j-1];
					if (temp>1)
						break;
				}
				if (temp>1)
					break;
			}
			if (temp>1)
				break;
		}
		
		n=n-1;
			
		for (int i=1;i<=4;i++)
			for (int j=1;j<=4;j++)
				A[n+i-1][flag+j-1]=B[i][j]+A[n+i-1][flag+j-1];

		for (int i=1;i<=15;i++)
		{
			for (int j=1;j<10;j++)
				cout<<A[i][j]<<" ";
			cout<<A[i][10]<<endl;
		}
		
	}
	return 0;
}