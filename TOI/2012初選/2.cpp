#include <bits/stdc++.h>

using namespace std;

void p(int *zero, int cur, int tar, int n, int &c, int truen){
	int i = 0;
	while(*(zero+cur*n+i)!=-1){
		if(cur==truen-1){
			if(tar<*(zero+cur*n+i)){
				c++;
			}
		}else if(tar<*(zero+cur*n+i)){
			p(zero, cur+1, *(zero+cur*n+i), n, c, truen);
		}
		i++;
	}
}

int main(){
	int m, n, temp=0, ans=0;
	cin >> m >> n;
	int portion[n] = {0};
	string s, tar;
	cin >> s;
	cin >> tar;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(s[j]==tar[i]){
				portion[i]++;
			}
		}
	}
	sort(portion, portion+n);
	int position[n][portion[n-1]+1];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(s[j]==tar[i]){
				position[i][temp]=j;
				temp++;
			}
		}
		position[i][temp] = -1;
		temp = 0;
	}
	int i = 0;
	while(position[0][i]!=-1){
		p(position[0], 1, position[0][i], portion[n-1]+1, ans, n);
		i++;
	}
	cout << ans << endl;
	return 0;
}
