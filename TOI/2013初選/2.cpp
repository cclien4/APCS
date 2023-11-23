#include <bits/stdc++.h>

using namespace std;

int addup(int *p, int n){
	int a = 0;
	for(int i = 0; i < n; i++){
		a+=abs(*(p+i));
	}
	return a;
}

int main(){
	int n, temp, x = 0, l, ri = 0, le = 0, mi = 0, ans;
	cin >> n;
	int move[n];
	for(int i = 0; i < n; i++){
		cin >> temp >> l;
		move[i] = temp-x;
		if(move[i]>0){
			le++;
		}else if(move[i]<0){
			ri++;
		}else{
			mi++;
		}
		x+=l;
	}
	while(le+mi<ri){
		le = 0; mi = 0; ri = 0;
		for(int i = 0; i < n; i++){
			move[i]++;
			if(move[i]>0){
				le++;
			}else if(move[i]<0){
				ri++;
			}else{
				mi++;
			}
		}
	}
	ans = addup(move, n);
	while(ri+mi<le){
		le = 0; mi = 0; ri = 0;
		for(int i = 0; i < n; i++){
			move[i]--;
			if(move[i]>0){
				le++;
			}else if(move[i]<0){
				ri++;
			}else{
				mi++;
			}
		}
	}
	temp = addup(move, n);
	ans = temp<ans?temp:ans;
	cout << ans << endl;
	return 0;
}

