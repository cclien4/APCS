#include <bits/stdc++.h>
#define int long long
#define N 105
#define IOS ios::sync_with_stdio(0),cin.tie(0)
using namespace std;
int n,A[N];

signed main(){
    IOS;
    cin>>n;
    for(int i=0;i<n;i++)cin>>A[i];
    int ans = 0;
    if(A[0] == 0)ans += A[1];
    if(A[n-1] == 0)ans += A[n-2];
    for(int i=1;i<n-1;i++){
        if(A[i] == 0)ans += min(A[i-1],A[i+1]);
    }
    cout<<ans<<endl;
}
