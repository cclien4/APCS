#include <cstdio>
#include <algorithm>
using namespace std;


int main(void)
{
	int score[20];	//�̦h20�����Z 
	int num,i; 		//�X�ӤH 
	//int max=0,min=0;		//�洫�Ȧs���H 
	
	while(scanf("%d",&num)!=EOF){

	//��J�}�C 
	for(i=0;i<num;i++){
		scanf("%d",&score[i]);
	}
	//�i��Ƨ�  �ϥ�algorithm��sort 
	sort(score,score+num);
	//�����̰��γ̧C�� 
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
	
	//��X�D�ةһݮ榡 
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
