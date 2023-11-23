#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 2147483647;
array<int, 104> C, I;
array<string, 50004> S;
array<array<int, 104>, 50004> H;
array<set<int>, 104> Z;
int pow(int x, int k){
    int ans = 1;
    for(int i = 1; i <= k; i <<= 1){
        if(i & k) ans = ans * x % mod;
        x = x * x % mod;
    }
    return ans;
}
void build(int n){
    C[0] = I[0] = 1;
    for(int i = 1; i <= n; i++){
        C[i] = 29 * C[i - 1] % mod;
        I[i] = pow(C[i], mod - 2);
    }
}
void hsah(string &s, int p){
    int n = s.size();
    H[p][0] = s[0] - 'a' + 1;
    for(int i = 1; i < n; i++){
        H[p][i] = (H[p][i - 1] + (s[i] - 'a' + 1) * C[i]) % mod;
    }
    Z[n].insert(H[p][n - 1]);
}
int see(int p, int l, int r){
    if(!l) return H[p][r];
    return ((H[p][r] - H[p][l - 1] + mod) % mod) * I[l] % mod;
}
int match(int m){
    int ans = 0, n;
    for(int i = 0; i < m; i++){
        n = S[i].size();
        for(int j = 1; j < n; j++){
            if(2 * j <= n) continue;
            if(see(i, 0, n - j - 1) == see(i, j, n - 1)){
                if(Z[2 * j - n].find(see(i, n - j, j - 1)) != Z[2 * j - n].end()) ans++;
            }
        }
    }
    return ans;
}
signed main(){
    int m;
    cin >> m;
    build(101);
    for(int i = 0; i < m; i++){
        cin >> S[i];
        hsah(S[i], i);
    }
    cout << match(m) << "\n";
    return 0;
}
