#include <bits/stdc++.h>

using namespace std;

struct road{
	int start;
	int finish;
	int l;
};

bool cmp(road r1, road r2){
	if(r1.l<r2.l){
		return true;
	}else{
		return false;
	}
}

bool search(bool* z, int cur, int former, int n){//0~n-1
	if(cur==n-1){
		return true;
	}
	for(int i = 0; i < n; i++){
		if(i!=cur&&i!=former){
			if(*(z+cur*n+i)){
				if(search(z, i, cur, n)){
					return true;
				}
			}
		}
	}
	return false;
}

int main(){
	int n, c=0, temp;
	cin >> n;
	road r[n*(n-1)/2];
	bool m[n][n];
	for(int i = 0; i < n*(n-1)/2; i++){
		for(int j = 0; j < n*(n-1)/2; j++){
			m[i][j] = false;
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(j>i){
				cin >> r[c].l;
				r[c].start = i;
				r[c].finish = j;
				c++;
			}else{
				cin >> temp;
			}
		}
	}
	sort(r, r+n*(n-1)/2, cmp);
	for(int i = 0; i < n*(n-1)/2; i++){
		m[r[i].start][r[i].finish] = true;
		m[r[i].finish][r[i].start] = true;
		if(r[i].start==0||r[i].finish==n-1){
			if(search(m[0], 0, 0, n)){
				cout << r[i].l << endl;
				break;
			}
		}
	}
	return 0;
}
