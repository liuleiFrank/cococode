#include <iostream>
#include <string>

using namespace std;

typedef struct node
{
	string str;
}node;//�洢ģ�� 

typedef struct node1 
{
	string var1;
	string var2;
}node1;//�洢������ֵ 

int main()
{
	node mb[110];
	node1 bl[110];
	string var;
	int m,n,i,j,k;
	while (scanf("%d %d",&m,&n)!=EOF)
	{
		cin.get();//���ջس�
		 
		// ����ģ�� 
		for (i=1;i<=m;i++)
			getline(cin,mb[i].str);
			
		// ������� 
		for (i=1;i<=n;i++)
		{
			getline(cin,var);
			int a=var.find(" ");
			int b=var.length();
			bl[i].var1.append(var,0,a);//���� 
			bl[i].var2.append(var,a+2,b-a-3);//ֵ 
		}
			
		for (i=1;i<=m;i++)
		{
			int c=0;
			int d=0;
			//ȷ���滻���Ĳ����ٱ��滻����û����Ҫ���滻�� 
			for (k=1;   mb[i].str.find("{{ ",d)!=string::npos  &&  mb[i].str.find(" }}",d)!=string::npos    ;k++) 
			{
				c=mb[i].str.find("{{ ",d);
				d=mb[i].str.find(" }}",d);
				string var3(mb[i].str,c+3,d-c-3);//��Ҫ�滻�Ĳ��� 
				
				int flag=0;
				//�������ж���ı��� 
				for (j=1;j<=n;j++)
				{
					if (bl[j].var1==var3) 
					{
						mb[i].str.replace(c,d-c+3,bl[j].var2);//�滻 
						d=c+bl[j].var2.length();//ȷ���滻���Ĳ����ٱ��滻 
						flag=1;
						break;
					}
				}
				if (flag==0)
					mb[i].str.replace(c,d-c+3,"");//���޶����滻Ϊ�� 
				
			}
			cout<<mb[i].str<<endl;
		}
		
		//��� 
		for (i=1;i<110;i++)
		{
			mb[i].str.erase();
			bl[i].var1.erase();
			bl[i].var2.erase();
		}
	}
	
	return 0;
}