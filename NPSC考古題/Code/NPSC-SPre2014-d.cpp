#include<bits/stdc++.h>
using namespace std;
 
struct P{int tp,l,r ;};
vector<P> v ;
char s[20001] ;
 
void query(int x,int l,int r,int inv)
{
    //printf("\nquery %d %d %d %d\n",x,l,r,inv) ;
    if(l>r) return ;
    if(x==0)
    {
        if(!inv) for(int i=l;i<=r;i++) putchar(s[i]) ;
        else for(int i=r;i>=l;i--) putchar(s[i]) ;
        return ;
    }
    int tp=v[x-1].tp , L=v[x-1].l , R=v[x-1].r ;
    if(tp==2)
    {
        if(l>R) query(x-1,l-(R-L+1),r-(R-L+1),inv) ;
        else if(r<=R) query(x-1,l,r,inv) ;
        else if(!inv)
        {
            query(x-1,l,R,0) ;
            query(x-1,R+1-(R-L+1),r-(R-L+1),0) ;
        }
        else
        {
            query(x-1,R+1-(R-L+1),r-(R-L+1),1) ;
            query(x-1,l,R,1) ;
        }
    }
    else if(tp==3)
    {
        if(r<L) query(x-1,l,r,inv) ;
        else if(l>R) query(x-1,l,r,inv) ;
        else if(l<L && r>=L && r<=R)
        {
            if(!inv)
            {
                query(x-1,l,L-1,0) ;
                query(x-1,L+R-r,R,1) ;
            }
            else
            {
                query(x-1,L+R-r,R,0) ;
                query(x-1,l,L-1,1) ;
            }
        }
        else if(l>=L && l<=R && r>R)
        {
            if(!inv)
            {
                query(x-1,L,L+R-l,1) ;
                query(x-1,R+1,r,0) ;
            }
            else
            {
                query(x-1,R+1,r,1) ;
                query(x-1,L,L+R-l,0) ;
            }
        }
        else if(l<L && r>R)
        {
            if(!inv)
            {
                query(x-1,l,L-1,0) ;
                query(x-1,L,R,1) ;
                query(x-1,R+1,r,0) ;
            }
            else
            {
                query(x-1,R+1,r,1) ;
                query(x-1,L,R,0) ;
                query(x-1,l,L-1,1) ;
            }
        }
        else if(l>=L && l<=R && r>=L && r<=R)
        {
            if(!inv) query(x-1,L+R-r,L+R-l,1) ;
            else query(x-1,L+R-r,L+R-l,0) ;
        }
    }
}
 
main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        int n,m ; scanf("%d%d%s",&n,&m,s+1) ;
        v.clear() ; int cnt=0 ;
        for(int i=1;i<=m;i++)
        {
            int tp,l,r ; scanf("%d%d%d",&tp,&l,&r) ;
            if(tp==2 || tp==3) v.push_back((P){tp,l,r}) , cnt++ ;
            else
            {
                query(cnt,l,r,0) ;
                printf("\n") ;
            }
        }
    }
}
