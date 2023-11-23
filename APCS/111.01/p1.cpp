#include <bits/stdc++.h>
using namespace std;

signed main(){
    int n, d, hav = 1, lst, p, ans = 0;
    cin >> n >> d >> p;
    lst = p;
    for(int i = 1; i < n; i++){
        cin >> p;
        if(hav * (p - lst) >= d){
            if(hav > 0) ans += p - lst;
            hav *= -1;
            lst = p;
        }
    }
    cout << ans << "\n";
    return 0;
}
