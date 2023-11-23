#include <bits/stdc++.h>
#define pb push_back
#define mid (l + r) / 2
using namespace std;
struct e{
    int u, v;
};
int n;
array<bool, 10004> WA;
array<int, 20004> vis;
array<vector<e>, 10004> E;
array<vector<int>, 20004> G;
bool dfs(int u, int t){
    if(vis[u]) return 1;
    bool ans = 1;
    vis[u] = t;
    for(int v : G[u]){
        if(vis[v] == t) return 0;
        ans &= dfs(v, 3 - t);
    }
    return ans;
}
bool check(int p){
    bool ans = 1;
    for(int i = 0; i < n; i++){
        G[i].clear();
        vis[i] = 0;
    }
    for(int i = 0; i <= p; i++){
        for(auto [u, v] : E[i]){
            G[u].pb(v);
            G[v].pb(u);
        }
    }
    for(int i = 0; i < n; i++){
        ans &= dfs(i, 1);
    }
    return ans;
}
void BS(int l, int r){
    if(check(r)) return;
    while(l != r){
        if(check(mid)) l = mid + 1;
        else r = mid;
    }
    WA[l] = 1;
    E[l].clear();
}
signed main(){
    int m, p, k, a, b;
    cin >> n >> m;
    while(m--){
        cin >> a >> b;
        E[0].pb({a, b});
    }
    cin >> p >> k;
    for(int i = 1; i <= p; i++){
        for(int j = 0; j < k; j++){
            cin >> a >> b;
            E[i].pb({a, b});
        }
    }
    for(int i = 0; i < 3; i++){
        BS(0, p);
    }
    for(int i = 1; i <= p; i++){
        if(WA[i]) cout << i << "\n";
    }
    return 0;
}
