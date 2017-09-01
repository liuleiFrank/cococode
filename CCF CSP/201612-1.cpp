#include <iostream>
using namespace std;
int A[1001];
int main()
{
	int n;
	while (cin>>n)
	{
		for (int i=1;i<=n;i++)
			cin>>A[i];
			

		int flag=0;
		for (int i=1;i<=n;i++)
		{
			int num1=0;
			int num2=0;
			for (int j=1;j<i;j++)
			{
				if (A[j]>A[i])
					num1++;
				else if(A[j]<A[i])
					num2++;
			}
			for (int j=i+1;j<=n;j++)
			{
				if (A[j]>A[i])
					num1++;
				else if(A[j]<A[i])
					num2++;
			}
			if (num1==num2)
			{
				flag=1;
				cout<<A[i]<<endl;
				break;
			}
		}
		if (flag==0)
			cout<<-1<<endl;		
	}

	return 0;
}