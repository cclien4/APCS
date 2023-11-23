#include <iostream>
#include <string>
using namespace std;

int main(void) {
	int n;
	cin >> n; // n組測資
	for (int i = 0; i < n; i++) {
		string goal, sample;
		int cnt = 0; //記錄有幾組match
		cin >> goal >> sample;
		if (goal.length() != 3 || goal[0] != goal[2]) { //不合格式輸出-1
			cout << -1 << endl;
			continue;
		}

		for (int itr = 0; itr < sample.length() - 3; itr++) {
			if (sample.substr(itr, 3) == goal) cnt++; //每次抓三個字元，對了就cnt++
		}
		cout << cnt << endl;
	}
}