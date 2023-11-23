#include <cstdio>
#include <algorithm>
using namespace std;


int after[10][10]; //�̫᪺�}�C 
int before[10][10]; //before

void Overturn(int R,int C)
{
	int temp;
	for(int i=0;i<(R/2);i++)
	{
		for(int j=0;j<C;j++)
		{
			temp=after[i][j];
			after[i][j]=after[R-1-i][j];
			after[R-1-i][j]=temp;
		}
	}
}

void rotation(int R,int C)
{
	//------�i����x�}�ʧ@ ----------
	for(int i=0;i<C;i++)
	{
		for(int j=0;j<R;j++)
		{
			before[i][j]=after[j][C-1-i];
		}
	}
	//-------�i�����᪺����---------
	for(int i=0;i<C;i++)
	{
		for(int j=0;j<R;j++)
		{
			after[i][j]=before[i][j];
		}
	}
	 
}
int main()
{

	int R,C,M; 		//��J���}�C�ξާ@ 
	int max=0,min=0;		
	while(scanf("%d %d %d",&R,&C,&M)!=EOF){
    	int otrt[10];//Overturn and rotation
    	int count_m0=0,flag=0;//�Φbrotation�P�O 
    	max=0,min=0;
    	//��J�}�C���e 
    	for(int i=0;i<R;i++)
    	{
    		for(int j=0;j<C;j++)
    		{
    			scanf("%d",&after[i][j]);
    		}
    	}
    	//��J���O���e
    	for(int i=0;i<M;i++)
    	{
    		scanf("%d",&otrt[i]);
    		if(otrt[i]==0)
    			count_m0++;
    	}
    	
    	//�i�����άO½�઺�P�O
    	for(int i=M-1;i>=0;i--)
    	{
    		if(otrt[i]==1 && flag==0)
    		{
    			Overturn(R,C);
    		}
    		else if(otrt[i]==1 && flag==1)
    		{
    			Overturn(C,R);
    		}
    		else if(otrt[i]==0 && flag==0)
    		{
    			rotation(R,C);
    			flag=1;
    		}
    		else
    		{
    			rotation(C,R);
    			flag=0;
    		}
    			
    	} 
    	
    	if(count_m0==0 || count_m0%2==0)
    	{
    		printf("%d %d\n",R,C);
    		for(int i=0;i<R;i++)
    		{
    			for(int j=0;j<C;j++)
    			{
    				printf("%d ",after[i][j]);
    			}
    			printf("\n");
    		}
    	}
    	else
    	{
    		printf("%d %d\n",C,R);
    		for(int i=0;i<C;i++)
    		{
    			for(int j=0;j<R;j++)
    			{
    				printf("%d ",after[i][j]);
    			}
    			printf("\n");
    		}
    	}
     }

	
	return 0;
}
