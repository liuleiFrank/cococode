#include <stdio.h>

int main()
{
	int y;
	int d;
	int M[13];
	M[1]=31;
	M[2]=28;
	M[3]=31;
	M[4]=30;
	M[5]=31;
	M[6]=30;
	M[7]=31;
	M[8]=31;
	M[9]=30;
	M[10]=31;
	M[11]=30;
	M[12]=31;
	while (scanf("%d %d",&y,&d)!=EOF)
	{
		if ( (y%4==0&&y%100!=0) || (y%400==0) )
			M[2]=29;
		else 
			M[2]=28;
		
		int sum=0;
		int i;
		for (i=1;i<=12;i++)
		{
			sum=sum+M[i];
			if (sum>d)
				break;
		}
		printf("%d\n%d\n",i,d-sum+M[i]);
	}
	return 0;
}



