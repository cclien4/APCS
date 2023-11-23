#include<stdio.h>
#include<string.h>

int main()
{
	char str[501]={};
	scanf("%s",str);

	int length = strlen(str);
	
	if( length % 2 != 0 ){
		printf("NO\n");
		return 0;
	}

	char front_str[251]={};
	strncpy( front_str, str, length/2 );

	char back_str[251]={};
	for(int i=0; i<length/2; i+=1)
	{
		back_str[i] = str[ (length - 1) - i ];
	}

	if( strncmp( front_str, back_str, length/2 ) == 0){
		printf("YES\n");
		printf("%s\n",front_str );
	}
	else 
		printf("NO\n");

}
