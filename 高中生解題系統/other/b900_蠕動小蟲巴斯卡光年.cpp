#include <bits/stdc++.h>

using namespace std;

int main(){
	int w, l;
	char c;
	cin >> w >> l;
	bool map[l][w-1];
	string str[l];
	for(int i = 0; i < l; i++){
		cin >> str[i];
		for(int j = 1; j < w*2-1; j+=2){
			if(str[i][j]=='.'){
				map[i][(j-1)/2] = false;
			}else{
				map[i][(j-1)/2] = true;
			}
		}
	}
	for(int i = 0; i < w; i++){
		int cur = i;
		for(int j = 0; j < l; j++){
			if((cur==0)?(0):(map[j][cur-1])){
				cur--;
			}else if((cur==w-1)?(0):(map[j][cur])){
				cur++;
			}
		}
		cur++;
		cout << cur << ' ';
	}
	cout << endl;
	return 0;
}
/*
5 6
|.|.|-|.|
|.|.|.|.|
|.|.|.|.|
|.|-|.|.|
|.|.|-|.|
|.|.|.|.|
4 9
|.|.|-|
|-|.|.|
|.|.|-|
|.|-|.|
|-|.|.|
|.|-|.|
|.|.|-|
|-|.|.|
|.|.|.| 
*/
