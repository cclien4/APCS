#include <cstdio>
#include <algorithm>
using namespace std;


int main(void)
{
	int score[20];	//最多20筆成績 
	int num,i; 		//幾個人 
	//int max=0,min=0;		//交換暫存的人 
	
	while(scanf("%d",&num)!=EOF){

	//輸入陣列 
	for(i=0;i<num;i++){
		scanf("%d",&score[i]);
	}
	//進行排序  使用algorithm的sort 
	sort(score,score+num);
	//紀錄最高及最低值 
/*	for(int i=0;i<num;i++)  //TLE
	{
		if(score[i]<60)
			max=i;
		if(score[i]>60)
		{
			min=i;
			break;
		}
	}
	*/
	
	//輸出題目所需格式 
	for(i=0;i<num;i++){
		if(i!=num-1)
		printf("%d ",score[i]);
		else
		printf("%d",score[i]);
	}
	
	if(score[0]>=60){
		printf("\nbest case");
		printf("\n%d\n",score[0]);
	}
	else if(score[num-1]<60){
		printf("\n%d",score[num-1]);
		printf("\nworst case\n");
	}else{
		for(i=1;i<num;i++){
			if(score[i-1] < 60 && score[i]>=60){
					printf("\n%d",score[i-1]);
					printf("\n%d\n",score[i]);
				}
				
		}
	}

	
}
	return 0;
}
