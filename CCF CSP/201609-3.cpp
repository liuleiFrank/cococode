#include <iostream>
#include <string>
using namespace std;

typedef struct WJ
{
	int flag;
	int health;
	int attack;
}WJ;

WJ X[8];
WJ H[8];

int main()
{
	int n;
	int XH=1;
	int a,b,c;
	int aer,der;
	int xscnum,hscnum;
	while (cin>>n)
	{
		X[0].flag=1;
		H[0].flag=1;
		
		X[0].health=30;
		H[0].health=30;
		
		X[0].attack=0;
		H[0].attack=0;
		
		for (int i=1;i<=7;i++)
		{
			X[i].flag=0;
			H[i].flag=0;
		}
		
		xscnum=0;
		hscnum=0;
		
		for (int kk=1;kk<=n;kk++)
		{
			getchar();
			
			string str;
			cin>>str;
			
			if (str=="summon" )	//召唤随从 
			{
				cin>>a>>b>>c;
				
				if (XH==1)
				{
					if (X[a].flag==1) //进场移动 
					{
						for (int j=xscnum;j>=a;j--)
						{
							X[j+1].flag=1;
							X[j+1].health=X[j].health;
							X[j=1].attack=X[j].attack; 
						}
					}
					X[a].flag=1;
					X[a].health=c;
					X[a].attack=b;
					xscnum++;
				}
				else if (XH==2)
				{
					if (H[a].flag==1) //进场移动 
					{
						for (int j=hscnum;j>=a;j--)
						{
							H[j+1].flag=1;
							H[j+1].health=H[j].health;
							H[j+1].attack=H[j].attack; 
						}
					}
					H[a].flag=1;
					H[a].health=c;
					H[a].attack=b;
					hscnum++;
				}
			}
			else if (str=="end") //回合转换 
			{
				if (XH==1)
					XH=2;
				else if (XH==2)
					XH=1;
			}
			else if (str=="attack") //攻击 
			{
				cin>>aer>>der;
				
				if (XH==1) //先手回合攻击时 
				{
					//结算 
					X[aer].health=X[aer].health-H[der].attack;
					H[der].health=H[der].health-X[aer].attack;
					
					if (X[aer].health<=0) //死亡退场 
					{
						for (int j=aer;j<xscnum;j++)
						{
							X[j].flag=1;
							X[j].health=X[j+1].health;
							X[j].attack=X[j+1].attack; 
						}
						X[xscnum].flag=0;
						xscnum--;
					}
					
					if (H[der].health<=0) //死亡退场 
					{
						for (int j=der;j<hscnum;j++)
						{
							H[j].flag=1;
							H[j].health=H[j+1].health;
							H[j].attack=H[j+1].attack; 
						}
						H[hscnum].flag=0;						
						hscnum--;
					}
				}
				else if (XH==2) //后手回合攻击时 
				{
					H[aer].health=H[aer].health-X[der].attack;
					X[der].health=X[der].health-H[aer].attack;
					
					if (H[aer].health<=0) //死亡退场 
					{
						for (int j=aer;j<hscnum;j++)
						{
							H[j].flag=1;
							H[j].health=H[j+1].health;
							H[j].attack=H[j+1].attack; 
						}
						H[hscnum].flag=0;						
						hscnum--;
					}
					
					if (X[der].health<=0) //死亡退场 
					{
						for (int j=der;j<xscnum;j++)
						{
							X[j].flag=1;
							X[j].health=X[j+1].health;
							X[j].attack=X[j+1].attack; 
						}
						X[xscnum].flag=0;
						xscnum--;
					}
				}
			}
		}
		
		//输出 
		if (X[0].health * H[0].health <=0 )
		{
			if (X[0].health<=0)
				cout<<1<<endl;
			else if (H[0].health<=0)
				cout<<-1<<endl;
		}
		else 
			cout<<0<<endl;
			
		cout<<X[0].health<<endl;
		cout<<xscnum<<" ";
		for (int i=1;i<xscnum;i++)
			cout<<X[i].health<<" ";
		cout<<X[xscnum].health<<endl;
		
		cout<<H[0].health<<endl;
		cout<<hscnum<<" ";
		for (int i=1;i<hscnum;i++)
			cout<<H[i].health<<" ";
		cout<<H[hscnum].health<<endl;
	}
	return 0;
}