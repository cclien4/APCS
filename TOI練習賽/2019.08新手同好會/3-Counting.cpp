#include <stdio.h>
int main()
{
    int num[1005]= {}, count[1005]= {};
    int N=0, L=0;
    scanf("%d",&N);
    while(N>0)
    {
        int check=0, M=0;
        scanf("%d",&M);
        for(int i=0; i<L; i+=1)
        {
            if(num[i]==M)
            {
                count[i]+=1;
                check=1;
                break;
            }
        }
        if(check==0)
        {
            num[L]=M;
            count[L]+=1;
            L+=1;
        }
        N-=1;
    }
    int max=1, max_count=0;
    for(int i=0;i<L;i+=1)
    {
        if(count[i]>max)
        {
            max=count[i];
            max_count=1;
        }
        else if(count[i]==max && max!=1) max_count+=1;
    }

    printf("%d\n",L);
    if(max_count==0) printf("NO");
    if(max_count>=1)
    {
        for(int i=0;i<L;i+=1)
        {
            if(count[i]==max) printf("%d ",num[i]);
        }
    }
}
