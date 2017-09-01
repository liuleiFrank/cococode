#include <iostream>
#include <string>

using namespace std;

typedef struct node
{
	string str;
}node;//存储模板 

typedef struct node1 
{
	string var1;
	string var2;
}node1;//存储变量和值 

int main()
{
	node mb[110];
	node1 bl[110];
	string var;
	int m,n,i,j,k;
	while (scanf("%d %d",&m,&n)!=EOF)
	{
		cin.get();//吸收回车
		 
		// 输入模板 
		for (i=1;i<=m;i++)
			getline(cin,mb[i].str);
			
		// 输入变量 
		for (i=1;i<=n;i++)
		{
			getline(cin,var);
			int a=var.find(" ");
			int b=var.length();
			bl[i].var1.append(var,0,a);//变量 
			bl[i].var2.append(var,a+2,b-a-3);//值 
		}
			
		for (i=1;i<=m;i++)
		{
			int c=0;
			int d=0;
			//确保替换掉的不会再被替换，且没有需要再替换的 
			for (k=1;   mb[i].str.find("{{ ",d)!=string::npos  &&  mb[i].str.find(" }}",d)!=string::npos    ;k++) 
			{
				c=mb[i].str.find("{{ ",d);
				d=mb[i].str.find(" }}",d);
				string var3(mb[i].str,c+3,d-c-3);//需要替换的部分 
				
				int flag=0;
				//搜索所有定义的变量 
				for (j=1;j<=n;j++)
				{
					if (bl[j].var1==var3) 
					{
						mb[i].str.replace(c,d-c+3,bl[j].var2);//替换 
						d=c+bl[j].var2.length();//确保替换掉的不会再被替换 
						flag=1;
						break;
					}
				}
				if (flag==0)
					mb[i].str.replace(c,d-c+3,"");//若无定义替换为空 
				
			}
			cout<<mb[i].str<<endl;
		}
		
		//清除 
		for (i=1;i<110;i++)
		{
			mb[i].str.erase();
			bl[i].var1.erase();
			bl[i].var2.erase();
		}
	}
	
	return 0;
}