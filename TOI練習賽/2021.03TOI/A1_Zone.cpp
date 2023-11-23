#include<stdio.h>

int main()
{
	int a=0,b=0,sec=0,zone=0;
	scanf("%d %d %d %d",&a,&b,&sec,&zone);
	int hour=zone;
	int minutes=30*zone+b;
	if(minutes>=60)
	{
		while(minutes>=60)
		{
			minutes-=60;
			hour+=1;
		}
	}
	else
	{
		while(minutes<60)
		{
			minutes+=60;
			hour-=1;
		}
	}
	if(minutes>=60)
	{
		minutes-=60;
		hour+=1;
	}
	int tran_hour=hour+a;
	if(tran_hour>36)
	{
		tran_hour-=36;
	}
	else if (tran_hour<0)
	{
		tran_hour+=36;
	}
	printf("%d:%02d:%02d\n",tran_hour,minutes,sec);
}
