#include<bits/stdc++.h>
int main()
{
    long long arr[65]= {0,1};
    for(long long i=2; i<61; i+=1)
    {
        arr[i]=arr[i-1]*2;
    }
    long long n,i;
    scanf("%lld%lld",&n,&i);
    long long goal=(i-1)^i;
    long long mov=-1;
    for(long long j=60; j>=1; j-=1)
    {
        if(goal>=arr[j])
        {
            mov=j;
            break;
        }
    }
    long long base=6*arr[mov];
    long long step=i%base;
    long long from,to;
    long long temp=(n+mov)&1;
    if(step*2 < base)
    {
        from=1;
        if(temp&1)
        {
            to=2;

        }
        else to=3;
    }
    else if(step*2 == base)
    {

        if(temp&1)
        {
            from=2;
            to=3;
        }
        else
        {
            from=3;
            to=2;
        }
    }
    else
    {
        if(temp&1)
        {
            from=3;
            to=1;
        }
        else
        {
            from=2;
            to=1;

        }
    }
    printf("move %lld from %lld to %lld\n",mov,from,to);

}
