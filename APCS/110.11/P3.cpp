#include <bits/stdc++.h>
#define int long long
#define N 200005
#define IOS ios::sync_with_stdio(0),cin.tie(0)
using namespace std;
int n,m,A[N],B[N];

signed main(){
    IOS;
    memset(A,0,sizeof(A));
    cin>>n>>m;
    while(m--){
        int x,y,w;cin>>x>>y>>w;
        A[x] += w;
        A[y+1] -= w;
    }
    for(int i=1;i<=n;i++)cin>>B[i];
    for(int i=1;i<=n;i++)A[i] = A[i] + A[i-1];
    sort(A+1,A+n+1);
    sort(B+1,B+n+1);
    int ans = 0;
    for(int i=1;i<=n;i++){
        ans += A[i] * B[n-i+1];
    }
    cout<<ans<<endl;
}
