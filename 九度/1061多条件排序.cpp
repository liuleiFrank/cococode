#include <stdio.h>
#include <string.h>

typedef struct Data
{
	char str[101];
	int age;
	int score;
}Data;

int main()
{
	int N;
	Data D[1001];
	while (scanf("%d",&N)!=EOF)
	{
		scanf("%s %d %d",&D[1].str,&D[1].age,&D[1].score);
		for (int kk=2;kk<=N;kk++)
		{
			scanf("%s %d %d",&D[0].str,&D[0].age,&D[0].score);
			int i;
			for (i=kk-1; D[i].score>D[0].score || ( D[i].score==D[0].score && strcmp( D[i].str , D[0].str )>0 ) || ( D[i].score==D[0].score && strcmp( D[i].str , D[0].str )==0 && D[i].age>D[0].age ) ;i--)   
			{
					D[i+1]=D[i];
			}
			D[i+1]=D[0];
		}

		for (int kk=1;kk<=N;kk++)
			printf("%s %d %d\n",D[kk].str,D[kk].age,D[kk].score);
	}
	return 0;
}