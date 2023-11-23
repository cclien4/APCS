#include<stdio.h>
#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
int main(){
	string rule,s;
	cin >> rule >> s;
	map<char,int>m;
	for(int i=0 ; i < rule.size() ; i+=1){
		m[rule[i]] = i;
	}
	int Count[30]={0};
	for(int i=0 ; i < s.size() ; i+=1 ){
		Count[m[s[i]]] += 1;
	}
	for(int i=1 ; i < rule.size() ; i+=1 ){
		Count[i] += Count[i-1];
	}
	int N = 0,num;
	cin >> N;
	while(N--){
		cin >> num;
		int temp = lower_bound(Count,Count+rule.size(),num) - Count;
		cout << rule[temp] << endl;
	}
}
