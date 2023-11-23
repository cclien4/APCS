#include<stdio.h>
int statue[5005]={};
void init(int n)
{
    for(int i=0;i<=n*2+2;i+=1)
    {
        statue[i]=i;
    }
}
int fin(int x)
{
    if(statue[x]!=x)
    {
        statue[x]=fin(statue[x]);
    }
    return statue[x];
}
void unin(int x,int y)
{
    int fx=fin(x);
    int fy=fin(y);
    if(fx!=fy)
    {
        statue[fy]=fx;
    }
    return;
}
int main()
{
    int n,t;
    while(scanf("%d%d",&n,&t)==2)
    {
        init(n);
        int a,b;
        char d1,d2;
        char status;
        for(int i=0;i<t;i+=1)
        {
            scanf("%d%c %d%c %c",&a,&d1,&b,&d2,&status);
            a=a*2+(d1=='R');
            b=b*2+(d2=='R');
            if(status=='D')
            {
                b^=1;
            }
            unin(a,b);
            unin(a^1,b^1);
        }
        int bad=0;
        for(int i=1;i<=n;i+=1)
        {
            int L=i*2,R=i*2+1;
            if(fin(L)==fin(R))
            {
                printf("Impossible\n");
                bad=1;
                break;
            }
        }
        if(!bad)
        {
            printf("Easy Peasy\n");
        }
    }
}
