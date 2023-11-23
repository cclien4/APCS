#include <cstdio>
#include <iostream>
#include <vector>
#define LL long long
using namespace std;

vector<LL> fib;

int Find(LL x) {
	for(int i=0;i<fib.size();i++) {
		if(fib[i] == x) return i+1;
	}
	return -1;
}

int main() {
	fib.push_back((LL)1);
	fib.push_back((LL)1);
	LL x = (LL)2;
	while( 0 < x && x < (LL)9e18) {
		fib.push_back(x);
		x = fib.back() + fib[fib.size()-2];
	}
	cout<<fib.size()<<endl;
	//
	vector<LL> Input;
	while(cin>>x) {
		Input.push_back(x);
	}
	//
	int Index = Find(Input.front());
	if(Index == -1) {
		cout<<Input.front()<<endl;
		return 0;
	}
	int tmp = Index-1;
	for(int i=1;i<Input.size();i++) {
		if(Input[i] != fib[tmp+1]) {
			cout<<Input[i]<<endl;
			return 0;
		}
		tmp++;
	}
	cout<<Index<<endl;
	return 0;
}
