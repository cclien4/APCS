#include<bits/stdc++.h>
using namespace std;
long long int DP[105][105] ={0};
int main(){
	for(int i=0;i<=50;i+=1){
		DP[i][0] = 1;
		DP[0][i] = 1;
	}
	for(int i=1;i<=50;i+=1){
		for(int j=1;j<=50;j+=1){
			DP[i][j] = DP[i][j-1] + DP[i-1][j-1];
		}
	}
	int N;
	cin >> N;
	while(N--){
		int D,C;
		cin >> D >> C;
		cout <<DP[D][C] << endl;
	}
}


