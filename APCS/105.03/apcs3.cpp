#include <stdio.h>

int main()
{
	int M[1001],N,ma,mb,sum;
	for(int i=0;i<1001;i++)
		M[i]=0;
	
	//cin>>N;
	while(scanf("%d",&N)!=EOF){
	sum=0;
	for(int i=0;i<1001;i++)
		M[i]=0;
	for(int i=0;i<N;i++)
	{
	    scanf("%d %d",&ma,&mb);
		
		for(int j=ma;j<mb;j++)
				M[j]=1;
    }
       
    for(int i=0;i<1001;i++)
    {
    	if(M[i]==1)
    	{
    		sum++;
    	//	printf("%d\n",i);
		}	
	}
    
    
    
    printf("%d\n",sum);
    }
	return 0;
	//system("pause");
} 
