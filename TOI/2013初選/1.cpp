#include <bits/stdc++.h>

using namespace std;

int main(){
	char l[101], n[100];
	bool sp = false;
	int a[26], b;
	for(int i = 0; i < 26; i++){
		a[i] = 0;
	}
	cin.getline(l, 101);
	cin.getline(n, 101);
	for(int i = 0; n[i]!='\0'; i++){
		b = n[i]-'A';
		a[b]++;
	}
	for(int i = 0; l[i]!='\0'; i++){
		if(l[i]!=' '){
			b = l[i]-'A';
			if(a[b]>0){
				if(sp){
					cout << ' ' << l[i];
					sp = false;
				}else{
					cout << l[i];
				}
			}else{
				break;
			}
		}else{
			sp = true;
		}
	}
	return 0;
}

