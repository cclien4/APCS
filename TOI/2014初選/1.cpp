#include <bits/stdc++.h>

using namespace std;

int main(){
	int div[] = {1,1,4,4,2,1,1,4,4,2};
	int value[][4] = {{0},{1},{2,4,8,6},{3,9,7,1},{4,6},{5},{6},{7,9,3,1},{8,4,2,6},{9,1}};
	int a, b, m, c = 0, ans = 0, t;
	cin >> a >> b;
	m = a>b?a:b;
	int i = 1;
	while(i <= m){
		if(i%10==0||i%10==1||i%10==5||i%10==6){
			t = i;
		} else {
			t = value[i%10][i%(div[i%10])-1];
		}
		c+=t; c%=10;
		if(i==a){
			ans += c;
		}
		if(i==b){
			ans += c;
		}
		++i;
	}
	cout << ans << endl;
	return 0;
}

