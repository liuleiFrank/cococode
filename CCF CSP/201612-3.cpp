#include <iostream>
#include <string>
using namespace std;

typedef struct Role
{
	string rolename;
	int privinum;
	string privi[11];
}Role;

typedef struct User
{
	string username;
	int rolenum;
	string role[11];
}User;

Role MRole[110];
User MUser[110];

int main()
{
	int p,r,u,q;
	while (cin>>p)
	{
		getchar();
		string privi;
		for (int i=1;i<=p;i++)
			getline(cin,privi);
		
		cin>>r;
		getchar();
		for (int i=1;i<=r;i++)
		{
			cin>>MRole[i].rolename;
			cin>>MRole[i].privinum;
			for (int j=1;j<=MRole[i].privinum;j++)
			{
				getchar();
				cin>>MRole[i].privi[j];
			}
		}
		
		cin>>u;
		getchar();
		for (int i=1;i<=u;i++)
		{
			cin>>MUser[i].username;
			cin>>MUser[i].rolenum;
			for (int j=1;j<=MUser[i].rolenum;j++)
			{
				getchar();
				cin>>MUser[i].role[j];
			}
		}
		
		cin>>q;
		for (int i=1;i<=q;i++)
		{
			getchar();
			string Quser;
			cin>>Quser;
			
			getchar();
			string Qprivi;
			cin>>Qprivi;
			
			int flag=0;
			int flag2=0;
			int max=0;
			for (int j=1;j<=u;j++)//每个用户 
			{
				if (MUser[j].username==Quser)//查询对应的用户 
				{
					for (int k=1;k<=MUser[j].rolenum;k++)//该用户的每个角色 
					{
						for (int s=1;s<=r;s++)//和角色库中的角色匹配 
						{
							if (MUser[j].role[k]==MRole[s].rolename)//该用户的角色匹配 
							{
								for (int t=1;t<=MRole[s].privinum;t++)//角色里的每个权限 
								{
									if (MRole[s].privi[t]==Qprivi)
									{
										cout<<"true"<<endl;
										flag=1;
										break;
									}
									else if (Qprivi.find (":",0)!=string::npos && MRole[s].privi[t].find (":",0)!=string::npos  )
									{
										int temp0 = Qprivi[ Qprivi.find(":",0)+1 ]-'0';
										int temp1=MRole[s].privi[t][MRole[s].privi[t].find (":",0)+1]-'0';
										if (   Qprivi.compare(0 , Qprivi.find (":",0), MRole[s].privi[t] ,0, MRole[s].privi[t].find (":",0) ) ==0 && temp0<=temp1 ) 
										{
											cout<<"true"<<endl;
											flag=1;
											break;
										}
									}
									else if (Qprivi.find (":",0)==string::npos && MRole[s].privi[t].find (":",0)!=string::npos)
									{
										if ( MRole[s].privi[t].compare( 0 , MRole[s].privi[t].find (":",0) , Qprivi ) ==0 )
										{
											int maxtemp=MRole[s].privi[t][ MRole[s].privi[t].find (":",0)+1 ]-'0';
											if (maxtemp>max)
												max=maxtemp;
											flag=1;
											flag2=1;
											break;
										}
									}
								}
								break;
							}
						}					
					}
					if (flag2==1)
							cout<<max<<endl;
					break;
				}
			}
			
			if (flag==0)
				cout<<"false"<<endl;
		}
		
	}
	return 0;
}