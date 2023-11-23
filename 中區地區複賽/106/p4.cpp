#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int tot = 0;
string s;

int main() {
	while(cin>>s) {
		tot = 0;
		int i = 0;
		int L = s.length()-1;
		bool odd = true;
		//Parse every 3 digits
		while(L >= i+2) {
			if(odd) {
				tot += 100 * (s[i]-'0') + 10 * (s[i+1]-'0') + (s[i+2]-'0');
				i += 3;
				odd = false;
			} else {
				tot += (s[i]-'0') + 10 * (s[i+1]-'0') + 100 * (s[i+2]-'0');
				i += 3;
				odd = true;
			}
		}
		//
		if(i == L+1) {
			cout<<tot % 997<<endl;
		} else if(i == L) {
			tot += (s[i]-'0');
			cout<<tot % 997<<endl;
		} else { 	//i+1 == L
			if(odd) {
				tot += 10 * (s[i]-'0') + (s[i+1]-'0');
			} else {
				tot += (s[i]-'0') + 10 * (s[i+1]-'0');
			}
			cout<<tot % 997<<endl;
		}
	}
	return 0;
}
