#include <cstdio>
#include <algorithm>
using namespace std;


int main()
{
	int score[20];	//最多20筆成績 
	int num; 		//幾個人 
	int max=0,min=0;		//交換暫存的人 
	scanf("%d",&num);
	
	//輸入陣列 
	for(int i=0;i<num;i++)
	{
		scanf("%d",&score[i]);
	}
	//進行排序  使用algorithm的sort 
	sort(score,score+num);
	//紀錄最高及最低值 
	for(int i=0;i<num;i++)
	{
		if(score[i]<60)
			max=i;
		if(score[i]>60)
		{
			min=i;
			break;
		}
	}
	
	
	//輸出題目所需格式 
	for(int i=0;i<num;i++)
	{
		printf("%d ",score[i]);
	}
	
	if(max==0 && score[0]>=60)
	{
		printf("\nbest case");
	}
	else
	{
		printf("\n%d",score[max]);
	}
	
	if(min==0 && score[0]<=60)
	{
		printf("\nworst case");
	}
	else
	{
		printf("\n%d",score[min]);
	}	
	
	return 0;
}
