#include<stdio.h>
#include<string.h>

int main()
{
	int n = 0, m = 0;
	char cur = '\0';
	scanf("%d",&n);
	scanf("%d %c", &m, &cur);

	double HaveMoney = 0;
	if( cur == 'T'){
		HaveMoney = n * 1.0;
	}
	else if( cur == 'U' ){
		HaveMoney = n / 30.9;
	}
	else if( cur == 'J' ){
		HaveMoney = n / 0.28;
	}
	else if( cur == 'E' ){
		HaveMoney = n / 34.5;
	}

	if(HaveMoney < m)
		printf("No Money\n");
	else
	{
		double remain = HaveMoney - m;
		printf("%c %.2f\n", cur, remain);
	}
}

