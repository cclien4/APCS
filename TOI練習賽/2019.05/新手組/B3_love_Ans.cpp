#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main()
{
	char str[1005]={};
	fgets(str, 1000, stdin);

	int k = 0;
	bool findlove = 0;
	while(findlove == false)
	{
		char tmp[1005]={};
		for(int i=0;i<strlen(str);i+=1)
		{
			tmp[i] = str[i];
			if(isalpha(tmp[i]))
			{
				char first ='\0';char last ='\0';

				if(isupper(tmp[i])){
					first = 'A';last = 'Z';
				}
				else if(islower(tmp[i])){
					first = 'a';last = 'z';
				}

				if((tmp[i] + k) > last) //over z
					tmp[i] = (k - (last - tmp[i] + 1)) + first;
				else
					tmp[i] = tmp[i] + k;
			}
		}

		for(int i=0;i<strlen(tmp);i+=1)
		{
			if( (strncmp(&tmp[i], "Love", 4) == 0) || (strncmp(&tmp[i], "love", 4) == 0))
			{
				findlove = true;
				break;
			}
		}

		if(findlove == true)
			break;
		else
			k += 1;
	}
	printf("%d", k);
	return 0;
}
