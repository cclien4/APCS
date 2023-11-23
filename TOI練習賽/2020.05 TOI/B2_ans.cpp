#include<stdio.h>
#define MOD 1000000007
int DP[1002][10][1024]={};
int main()
{

    for(int i=1;i<10;i+=1)
    {
        DP[1][i][1<<i]=1;
    }
    for(int N=2;N<=1000;N+=1)
    {
        for(int i=1;i<10;i+=1)
        {
            for(int j=0;j<1024;j+=2)
            {
                for(int d=-2;d<=2;d+=1)
                {
                    int last=i+d;
                    if(last<1 || last>9) continue;
                    DP[N][i][j|(1<<i)]+=DP[N-1][last][j];
                    DP[N][i][j|(1<<i)]%=MOD;
                }
            }
        }
    }
    int N,P,Q;
    scanf("%d",&N);
    while(N--)
    {
        scanf("%d%d",&P,&Q);
        printf("%d\n",DP[P][Q][1022]);
    }
}
