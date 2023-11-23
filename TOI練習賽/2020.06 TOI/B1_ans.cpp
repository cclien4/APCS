#include<stdio.h>
#include<algorithm>
struct plant
{
    int s,e;
};
bool cmp(plant a,plant b)
{
    return a.s<b.s;
}
int main()
{
    int M,T;
    scanf("%d%d",&M,&T);
    plant P[10005];
    int DP[10005]={};
    for(int i=0;i<T;i+=1)
    {
        scanf("%d %d",&P[i].s,&P[i].e);
    }
    std::sort(P,P+T,cmp);
    for(int i=0;i<T;i+=1)
    {
        int dis=P[i].e-P[i].s;
        int len=DP[P[i].s]+dis;
        for(int j=P[i].e;j<=M;j+=1)
        {
            if(len<=DP[j]) break;
            DP[j]=len;
        }
    }
    printf("%d\n",DP[M]);
}
