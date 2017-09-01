#include <iostream>
#include <string>
using namespace std;

int main()
{
	string list[11];
	int p;
	cin>>p;
	
	getchar();
	
	string curdir;
	getline(cin,curdir);
	int n=curdir.length();
	
	for (int i=1;i<=p;i++)
	{
		string str;
		getline(cin,str);
		int len=str.length();
		
		//空情形 
		if (len==0)
		{
			list[i]=curdir;
			continue;
		}
		
		// 相对路径开头情形 
		if (str[0]=='.'&&str[1]=='.')
		{
			int last=curdir.rfind('/');
			string curdir2=curdir;
			curdir2.erase(last,n-last);
			str.erase(0,2);
			str=curdir2+str;
		}
		
		// ./开头情形 
		if (str[0]=='.'&&str[1]!='.')
		{
			str.erase(0,1);
			str=curdir+str;
		}
		
		// 删除/./ 
		while ( str.find("/./")!=string::npos )
		{
			int pos=str.find("/./");
			str.erase(pos+1,2);
		}
		
		// 删除/../ 
		while ( str.find("/../")!=string::npos)
		{
			int pos=str.find("/../");
			if (pos==0)
			{
				str.erase(pos+1,3);
			}
			else 
			{
				int pos2=str.rfind('/',pos-1);
				str.erase(pos2+1,pos-pos2+3);
			}
		}
		
		// 删除// 
		while (str.find("//")!=string::npos)
		{
			int pos=str.find("//");
			str.erase(pos+1,1);
		}
		
		// 单独 / 情形 
		len=str.length();
		if (len==1 && str[0]=='/')
		{
			list[i]=str;
			continue;
		}
		
		// 末尾 / 情形 
		if (str.rfind('/') == (len-1))
			str.erase(str.rfind('/'),1);	
		
		list[i]=str;	
	}
	
	//输出 
	for (int i=1;i<=p;i++)
		cout<<list[i]<<endl;
	return 0;
}