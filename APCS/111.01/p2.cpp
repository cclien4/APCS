#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
int m;
array<int, 1004> S, T, los;
int fight(vector<int> &P){
    if(P.size() == 1) return P[0];
    int a, b, tmp;
    vector<int> W, F;
    for(int i = 0; i < P.size(); i += 2){
        if(i + 1 >= P.size()){
            W.pb(P[i]);
            continue;
        }
        a = P[i], b = P[i + 1];
        if(S[a] * T[a] < S[b] * T[b]) swap(a, b);
        tmp = S[a];
        S[a] += (S[b] * T[b]) / (T[a] << 1);
        T[a] += (S[b] * T[b]) / (tmp << 1);
        S[b] += S[b] >> 1;
        T[b] += T[b] >> 1;
        los[b]++;
        W.pb(a), F.pb(b);
    }
    for(int f : F){
        if(los[f] >= m) continue;
        W.pb(f);
    }
    return fight(W);
}
signed main(){
    int n, p;
    vector<int> P;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> S[i];
    for(int i = 1; i <= n; i++) cin >> T[i];
    for(int i = 0; i < n; i++){
        cin >> p;
        P.pb(p);
    }
    cout << fight(P) << "\n";
    return 0;
}
