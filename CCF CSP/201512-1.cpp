#include <iostream>
#include <string>
using namespace std;
int main()
{
	string n;
	while (getline(cin,n))
	{
		int num=n.length();
		int sum=0;
		int i;
		for (i=0;i<num;i++)
		{
			int a;
			a=n[i]-'0';
			sum=sum+a;
		}
		cout<<sum<<endl;
	}

	return 0;	
}