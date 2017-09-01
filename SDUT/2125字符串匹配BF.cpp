#include<stdio.h>
#include<string.h>

int main()
{
    char str1[110],str2[110];
    while(scanf("%s %s",&str1,&str2)!=EOF)
    {
        int flag=0;
        int len1=strlen(str1);
        int len2=strlen(str2);
        for(int i=0; i<len1; i++)
        {
            int j=0;
            while(str1[i]==str2[j])
            {
                i++;
                j++;
            }
            if(j>=len2)
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
            printf("YES\n");
        else 
			printf("NO\n");
    }
    return 0;
}