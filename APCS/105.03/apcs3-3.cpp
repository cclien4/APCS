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
        //��u�q���}�l���I�M�������I�����W�ߪ�evnet
        //�b�u�q���}�l���IL�B�Aevent +1
        v.push_back({L, 1});
        //�b�u�q���������IR�B�Aevent -1
        v.push_back({R, -1});
    }
    sort(v.begin(), v.end());
    //now���V�ثe�˵���event
    //event���Ӯy���Ii, �����@�ӥ����Ѷ}�϶�[i, i+1), �@�Q�X�q�u�q�л\
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
