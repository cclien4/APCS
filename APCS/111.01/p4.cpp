#include <bits/stdc++.h>
using namespace std;
array<int, 50004> W;
array<int, 200004> H;
int post(int n, int h){
    int con = 0, cnt = 0;
    for(int i = 0; i < n; i++){
        if(!W[cnt]) break;
        if(H[i] >= h) con++;
        else con = 0;
        if(con >= W[cnt]){
            con = 0;
            cnt++;
        }
    }
    return cnt;
}
int BIS(int n, int k){
    int l = 0, r = 1e9, mid;
    while(l != r){
        mid = ((l + r) >> 1) + 1;
        if(post(n, mid) < k) r = mid - 1;
        else l = mid;
    }
    return l;
}
signed main(){
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> H[i];
    for(int i = 0; i < k; i++) cin >> W[i];
    cout << BIS(n, k) << "\n";
    return 0;
}
