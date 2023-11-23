#include<bits/stdc++.h>
const long long MOD=1e9+7;
long long mod(long long a)
{
    if(a==0) return 1;
    else if(a==1) return 2;
    else if(a%2==0)
    {
        long long x=mod(a/2);
        return (x*x)%MOD;
    }
    else return (mod(a-1)*mod(1))%MOD;
}
int main()
{
    int a;
    scanf("%d",&a);
    while(a--)
    {
        long long x;
        scanf("%lld",&x);
        printf("%lld\n",mod(x-1));
    }
}
