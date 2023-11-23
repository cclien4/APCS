#include <iostream>
#include <vector>
#include <queue>
#include "memory.h"

using namespace std;

double smax[100001];
char ntV[100001];
struct rinfo{
    int b;
    double s;
} tmp;
struct road{
    vector<rinfo> v;
} r[100001];
queue<int> q;

int main(){
    int i, j, t, n, m, a, b, tmp2, qi;
    double s, qval, ans;
    bool avail;
    scanf("%d", &t);
    while( t-- )
    {
        scanf("%d%d", &n, &m);
        memset(ntV, 1, sizeof(ntV));
        for( i=0; i<=n-1; i++ )
            r[i].v.clear();
        while( !q.empty() ) q.pop();
            
        for( i=0; i<m; i++ )
        {
            scanf("%d%d%lf", &a, &b, &s);
            if( a<n && b<n && a>=0 && b>=0 )
            {
                tmp.b=b;
                tmp.s=s;
                r[a].v.push_back(tmp);
                tmp.b=a;
                tmp.s=s;
                r[b].v.push_back(tmp);
            }
        }
        if( n==1 )
            puts("No way.");
        else
        {
            tmp2=r[0].v.size();
            for( i=0; i<tmp2; i++ )
            {
                q.push(r[0].v[i].b);
                smax[r[0].v[i].b]=r[0].v[i].s;
                ntV[r[0].v[i].b]=0;
            }
            ntV[0]=0;
            while( !q.empty() )
            {
                qi=q.front();
                qval=smax[q.front()];
                tmp2=r[qi].v.size();
                for( j=0; j<tmp2; j++ )
                {
                    int dest=r[qi].v[j].b;
                    double ts=min(qval, r[qi].v[j].s);
                    if( ntV[dest] )
                    {
                        smax[dest]=ts;
                        ntV[dest]=0;
                        q.push(dest);
                    }
                    else if( ts>smax[dest] && dest!=0 )
                    {
                        smax[dest]=ts;
                        q.push(dest);
                    }
                }
                q.pop();
            }
            avail=true;
            for( i=1; i<=n-1; i++ )
                if( ntV[i] )
                {
                    avail=false;
                    break;
                }
            if( avail )
            {
                ans=smax[1];
                for( i=2; i<=n-1; i++ )
                    if( smax[i]<ans )
                        ans=smax[i];
                printf("%0.4lf\n", ans);
            }
            else
                puts("The empire of Arcturus is ending.");
        }
    }
    return 0;
}
