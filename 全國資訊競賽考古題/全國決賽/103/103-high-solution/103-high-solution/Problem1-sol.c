/*	Solver: Min-Zheng Shieh
	Expected Running Time: << 1sec
 */

#include<stdio.h>

int main()
{
	int x,y,z;
	char cmd[128];
	for(scanf("%s",cmd); cmd[0]!='E'; scanf("%s",cmd))
	{
		if(cmd[0]=='X')
			scanf("%d",&x);
		else if(cmd[0]=='Y')
			scanf("%d",&y);
		else if(cmd[0]=='U')
			scanf("%d",&z), y+=z;
		else if(cmd[0]=='D')
			scanf("%d",&z), y-=z;
		else if(cmd[0]=='L')
			scanf("%d",&z), x-=z;
		else if(cmd[0]=='R')
			scanf("%d",&z), x+=z;
	}
	printf("%d\n%d\n",x,y);
	return 0;
}
