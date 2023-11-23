#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
int main() {
    int N, L, R;
    cin >> N;
    vector<pair<int,int>> v;
    for (int i = 0; i < N; i++) {
        cin >> L >> R;
        //把線段的開始端點和結束端點視為獨立的evnet
        //在線段的開始端點L處，event +1
        v.push_back({L, 1});
        //在線段的結束端點R處，event -1
        v.push_back({R, -1});
    }
    sort(v.begin(), v.end());
    //now指向目前檢視的event
    //event為該座標點i, 對應一個左閉由開區間[i, i+1), 共被幾段線段覆蓋
    int now = 0, event = 0, ans = 0;
    for (int i = 0; i <= 1e7; i++) {
        while (now < (int)v.size() && v[now].first == i) {
            event += v[now].second;
            now++;
        }
        if (event > 0) {
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}
