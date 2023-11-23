#include<bits/stdc++.h>
using namespace std;
struct fans
{
    int ind=0;
    int donate=0;
}f[100005];
bool cmp(fans a,fans b)
{
    if(a.donate==b.donate) return a.ind<b.ind;
    return a.donate>b.donate;
}
int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    for(int i=0;i<a;i+=1)
    {
        f[i].ind=i;
    }
    for(int j=0;j<b;j+=1)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        f[x].donate+=y;
    }
    sort(f,f+a,cmp);
    for(int i=0;i<a;i+=1)
    {
        printf("%d %d\n",f[i].ind,f[i].donate);
    }
}
