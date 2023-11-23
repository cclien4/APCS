#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main()
{
	char str[5000]={};
	scanf("%s",str);
	for(int i=0;i<strlen(str);++i)
	{
		int cnt=0;
		if(str[i]=='+')
		{
			continue;
		}
		else if (str[i]=='-')
		{
			int temp=i+1;
			while(isalnum(str[temp]) || isalpha(str[temp]))
			{
				temp+=1;
				cnt+=1;
			}
			for(int j=i+cnt;j>i;j--)
			{
				printf("%c",str[j]);
			}
			i+=cnt;
		}
		else if (isalnum(str[i]) || isalpha(str[i]))
		{
			printf("%c",str[i]);
		}
	}
	printf("\n");
}
