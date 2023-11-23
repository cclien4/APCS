#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	char c;
	string temps;
	int ans[103]={0}, highest=0;
	while(cin >> n){
		if(n==0){
			break;
		}
		int tempi[103]={0};
		cin.get(c);
		cin >> temps;
		for(int i = temps.size(), j = 0; i >= 0; i--, j++){
			tempi[j]+=temps[i]-'0';
		}
		for(int i = 0; i <= temps.size(); i++){
			ans[i]+=tempi[i];
			if(ans[i]>=10){
				ans[i+1]+=ans[i]/10;
				ans[i]%=10;
			}
		}
	}
	for(int i = 0; i < 103; i++){
		if(ans[i]!=0){
			highest = i;
		}
	}
	for(int i = highest; i >= 1; i--){
		cout << ans[i];
	}
	cout << endl;
	return 0;
}

