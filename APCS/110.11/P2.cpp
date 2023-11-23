#include <bits/stdc++.h>
using namespace std;
int n, m, cnt = 0, ans = 0;
array<array<int, 104>, 104> R, C, I;
void add(int r, int c){
    bool ok;
    I[r][c] = 1;
    cnt++;
    if(C[r][c] || R[r][c]) cnt--;
    C[r][c] = R[r][c] = 0;
    ok = 0;
    for(int i = r + 1; i < n; i++){
        if(I[i][c]) ok = 1;
    }
    if(ok){
        for(int i = r + 1; i < n; i++){
            if(I[i][c] || R[i][c]) break;
            R[i][c]++;
            cnt += C[i][c] == 0;
        }
    }
    ok = 0;
    for(int i = r - 1; i >= 0; i--){
        if(I[i][c]) ok = 1;
    }
    if(ok){
        for(int i = r - 1; i >= 0; i--){
            if(I[i][c] || R[i][c]) break;
            R[i][c]++;
            cnt += C[i][c] == 0;
        }
    }
    ok = 0;
    for(int i = c + 1; i < m; i++){
        if(I[r][i]) ok = 1;
    }
    if(ok){
        for(int i = c + 1; i < m; i++){
            if(I[r][i] || C[r][i]) break;
            C[r][i]++;
            cnt += R[r][i] == 0;
        }
    }
    ok = 0;
    for(int i = c - 1; i >= 0; i--){
        if(I[r][i]) ok = 1;
    }
    if(ok){
        for(int i = c - 1; i >= 0; i--){
            if(I[r][i] || C[r][i]) break;
            C[r][i]++;
            cnt += R[r][i] == 0;
        }
    }
}
void pull(int r, int c){
    I[r][c] = 0;
    cnt--;
    for(int i = r + 1; i < n; i++){
        if(!R[i][c]) break;
        R[i][c]--;
        cnt -= C[i][c] == 0;
    }
    for(int i = r - 1; i >= 0; i--){
        if(!R[i][c]) break;
        R[i][c]--;
        cnt -= C[i][c] == 0;
    }
    for(int i = c + 1; i < m; i++){
        if(!C[r][i]) break;
        C[r][i]--;
        cnt -= R[r][i] == 0;
    }
    for(int i = c - 1; i >= 0; i--){
        if(!C[r][i]) break;
        C[r][i]--;
        cnt -= R[r][i] == 0;
    }
}
signed main(){
    int h, r, c, t;
    cin >> n >> m >> h;
    while(h--){
        cin >> r >> c >> t;
        if(t){
            pull(r, c);
        }else{
            add(r, c);
        }
        ans = max(ans, cnt);
    }
    cout << ans << "\n" << cnt;
    return 0;
}
