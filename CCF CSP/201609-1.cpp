#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	while (cin>>n)
	{
		int firstnum;
		cin>>firstnum;
		int value=0;
		for (int i=2;i<=n;i++)
		{
			int nextnum;
			cin>>nextnum;
			int temp=abs(nextnum-firstnum);
			if (temp>value)
				value=temp;
			firstnum=nextnum;
		}
		cout<<value<<endl;
	}
	return 0;
}