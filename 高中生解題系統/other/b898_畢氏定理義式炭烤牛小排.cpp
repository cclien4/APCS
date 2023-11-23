#include <bits/stdc++.h>

using namespace std;

struct side{
	string str;
	int l;
};

bool cmp(side s1, side s2){
	if(s1.l==s2.l){
		for(int i = 0; i < s1.l; i++){
			if(s1.str[i]-'0'>s2.str[i]-'0'){
				return false;
			}else if(s1.str[i]-'0'==s2.str[i]-'0'){
				continue;
			}else{
				return true;
			}
		}
	}else if(s1.l<s2.l){
		return true;
	}else{
		return false;
	}
}

int main(){
	int runtime;
	cin >> runtime;
	for(int i = 0; i < runtime; i++){
		side s[3];
		cin >> s[0].str >> s[1].str >> s[2].str;
		s[0].l=s[0].str.size();s[1].l=s[1].str.size();s[2].l=s[2].str.size();
		sort(s, s+3, cmp);
		cout << s[2].str << endl;
	}
	return 0;
}
