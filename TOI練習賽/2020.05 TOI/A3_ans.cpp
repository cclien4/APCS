#include<stdio.h>
int main()
{
    int N = 0;
	scanf("%d",&N);	
    int a[30] = {};
    for(int i=0; i<N; i+=1)
    {
        scanf("%d",&a[i]);
    }
    int fpos = 35, bpos = 35, flag = 0;
    for(int i=0; i<N; i+=1)
    {
        if(a[i]==1&&flag!=1)
        {
            fpos=i;
            flag=1;
        }
        if(a[i]==1)
        {
            bpos=i;
        }
    }
    
    int ans=0;
    for(int i=0; i<N; i+=1)
    {
        if(i>=fpos&&i<=bpos)
        {
            if(i==0 || i==N-1)
            {
            	continue;
            }
            else if(i!=N-1)
            {
                if(a[i]==0&&a[i-1]!=9&&a[i+1]!=9)
                {
                    ans+=1;
                }
            }
        }
    }
    printf("%d\n",ans);
    
}
