#include <bits/stdc++.h>
using namespace std;
#define AC ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define pii pair<int,int> 
#define f first
#define s second
bool cmp(pii a,pii b) {
    if(a.f==b.f) return a.s>b.s;
    else return a.f<b.f;
}
int main() {
    AC
    int n,x,y;
    while(cin>>n) {
        vector<pii> v;
        for(int i=0;i<n;i++) {
            cin>>x>>y;
            v.push_back({x,y});
        }
        sort(v.begin(),v.end(),cmp);
        int left=0,right=0,ans=0;
        for(int i=0;i<v.size();i++) {
            if(v[i].f>=left) {
                ans+=(right-left);
                left=v[i].f;
                right=v[i].s;
            }else if(v[i].s>left){
                right=v[i].s;
            }
        }
        ans+=(right-left);
        cout<<ans<<'\n';
    }
    return 0;
}
