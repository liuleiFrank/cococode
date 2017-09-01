#include <stdio.h>
#include <string.h>

typedef struct buy
{
	double price;
	int num;
	int flag;
}buy;

typedef struct sell
{
	double price;
	int num;
	int flag;
}sell;

buy mybuy[5000];
sell mysell[5000];

int chengjiao(int n,double price)
{
	int n1=0;
	int n2=0;
	int i;
	for (i=1;i<=n;i++)
	{
		if (mybuy[i].flag==1)
		{
			if (mybuy[i].price>=price)
				n1=n1+mybuy[i].num;
		}
		if (mysell[i].flag==1)
		{
			if (mysell[i].price<=price)
				n2=n2+mysell[i].num;
		}
	}
	if (n1>=n2)
		return n2;
	else
		return n1;
}

int main()
{
	char str[10];
	int n=1;
	int i;
	for (i=1;i<=5000;i++)
	{
		mybuy[i].flag=0;
		mysell[i].flag=0;
	} 
	char c;
	int k;
	for (k=1;k<=7;k++)
	{
		scanf("%s",str);
		if (str[0]=='b')
		{
			scanf("%lf",&mybuy[n].price);
			scanf("%d",&mybuy[n].num);
			scanf("%c",&c);
			mybuy[n].flag=1;
			n++;
		}
		else if (str[0]=='s')
		{
			scanf("%lf",&mysell[n].price);
			scanf("%d",&mysell[n].num);
			scanf("%c",&c);
			mysell[n].flag=1;
			n++;
		}
		else if (str[0]=='c')
		{
			int a;
			scanf("%d",&a);
			scanf("%c",&c);
			mybuy[a].flag=0;
			mysell[a].flag=0;
		}
	}
	printf("sss\n");
	int w;
	int wmax=0;
	double pricemax=0;
	for (i=1;i<=n;i++)
	{
		if (mybuy[i].flag==1)
		{
			w=chengjiao(n,mybuy[i].price);
			if (w>wmax || (w=wmax&&mybuy[i].price>pricemax) )
			{
				wmax=w;
				pricemax=mybuy[i].price;
			}
		}
		if (mysell[i].flag==1)
		{
			w=chengjiao(n,mysell[i].price);
			if (w>wmax || (w=wmax&&mysell[i].price>pricemax) )
			{
				wmax=w;
				pricemax=mysell[i].price;
			}
		}
	}
	printf("%lf %d\n",pricemax,wmax);

	return 0;
}