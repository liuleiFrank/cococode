#include <iostream>

using namespace std;

int A[31][31]; 

int B[31][31];

int main()
{
	int n,m;
	while (cin>>n>>m)
	{
		int i,j,k,a;

		for (i=1;i<=n;i++)
			for (j=1;j<=m;j++)
			{
				cin>>a;
				A[i][j]=a;
				B[i][j]=a;
			}
			
		
		for (i=1;i<=n;i++)
			for (j=1;j<=m;j++)
			{
				int temp=A[i][j];
				
				if (A[i-1][j]==temp && A[i+1][j]==temp)
				{
					B[i][j]=0;
					for (k=i;k<=n;k++)
					{
						if (A[k][j]==temp)
							B[k][j]=0;
						else 
							break;
					}
					for (k=i;k>=1;k--)
					{
						if (A[k][j]==temp)
							B[k][j]=0;
						else 
							break;
					}	
				}
				
				if (A[i][j-1]==temp && A[i][j+1]==temp)
				{
					B[i][j]=0;
					for (k=j;k<=m;k++)
					{
						if (A[i][k]==temp)
							B[i][k]=0;
						else 
							break;
					}
					for (k=j;k>=1;k--)
					{
						if (A[i][k]==temp)
							B[i][k]=0;
						else 
							break;
					}	
				}					
			}
			
		for (i=1;i<=n;i++)
		{
			for (j=1;j<m;j++)
				cout<<B[i][j]<<" ";
			cout<<B[i][m]<<endl;
		}
		
	} 
	return 0;	
}