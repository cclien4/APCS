#include<stdio.h>

int main()
{
	long long int N = 0;
	scanf("%lld",&N);
	
	int num[10] = {}; 
	long long int tmp = N;
    int AppearNum = 0;
    while(tmp > 0)
	{
		num[tmp%10] += 1;
		tmp /= 10;
	}
	for(int i=0;i<10;i+=1)
	{
		if (num[i] != 0)
		{
			AppearNum += 1;
		}
	}
	
    
    int frequency[10]={};
    int count = 0;
	for(int i=0;i<AppearNum;i+=1)
	{
		int max = 0;
		int maxpos = -1;
		for(int j=0;j<10;j+=1)
		{
			if(num[j] > max)
			{
				max = num[j];
				maxpos = j;
			}
		}
		frequency[count] = maxpos;
		count += 1;

		num[maxpos] = -1;
	}

	for(int i=0;i<count;i+=1)
	{
		printf("%d ",frequency[i]);
	}
}
