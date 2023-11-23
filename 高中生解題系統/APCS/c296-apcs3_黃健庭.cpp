#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n, m, k, now;
	vector<int> p;
	while (cin >> n >> m >> k) {
		p.clear();
		for (int i = 1; i <= n; i++) {
			p.push_back(i);
		}
		now = 0;
		for (int i = 0; i<k; i++) {
			now = (now + m - 1) % p.size();
			p.erase(p.begin() + now);//刪除被炸的人
		}
		if (p.size() == 1) cout << p[0] << endl;//只剩一個人
		else if (now == p.size()) cout << p[0] << endl;//最後一個人被刪除，第一個就是幸運的人
		else cout << p[now] << endl;
	}
}
