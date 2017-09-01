#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;
	while (cin>>str)
	{
		int i;
		int num=0;
		int count=0;
		for (i=0;i<=11;i++)
		{
			if (str[i]!='-')
			{
				int temp=str[i]-'0';
				num=num+(++count)*temp;
			}
		}
		
		int ans = num % 11;
		if (ans==str[12]-'0')
			cout<<"Right"<<endl;
		else
		{
			for (i=0;i<=11;i++)
				cout<<str[i];
			cout<<ans<<endl;	
		}
	}
	
	return 0;
}

