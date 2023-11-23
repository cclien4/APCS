#include <bits/stdc++.h>

using namespace std;

int c = 0, n, s, t = 0, ans = -1e8;

inline void dfs(int* pi, bool* pb, int x, int y){
	c += *pi;
	ans = c>ans?c:ans;
	if(t < s){
		//往上
		if(x!=0&&!*(pb-n)){
			*pb = true;
			++t;
			dfs(pi-n, pb-n, x-1, y);
		}
		//往右
		if(y!=n-1&&!*(pb+1)){
			*pb = true;
			++t;
			dfs(pi+1, pb+1, x, y+1);
		}
		//往下
		if(x!=n-1&&!*(pb+n)){
			*pb = true;
			++t;
			dfs(pi+n, pb+n, x+1, y);
		}
		//往左 
		if(y!=0&&!*(pb-1)){
			*pb = true;
			++t;
			dfs(pi-1, pb-1, x, y-1);
		}
		//走完了 
		--t;
		*pb = false;
		c -= *pi;
	}else{
		--t;
		*pb = false;
		c -= *pi;
	}
}

int main(){
	int x, y;
	cin >> n >> s;
	int map[n][n];
	bool v[n][n];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> map[i][j];
			v[i][j] = false;
		}
	}
	cin >> x >> y;
	dfs(map[x]+y, v[x]+y, x, y);
	cout << ans << endl;
	return 0;
}

