#include <cstdio>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#define Map map<string, int>
using namespace std;

int main() {
	string s;
	int p, q;
	Map Price, Quantity;
	vector<string> key;
	while(true) {
		cin>>s;
		if(s == "0000000000") break;
		cin>>p>>q;
		if(!Price.count(s)) { 
			Price.insert({s, p});
			Quantity.insert({s, q});
			key.push_back(s);
		} else {
			Quantity.find(s)->second += q;
		}
	}
	//Calculate total Price
	double total = 0.0;
	for(int i=0;i<key.size();i++) {
		string k = key[i];
		if(k[0] == 'X') {
			p = Price.find(k)->second;
			q = Quantity.find(k)->second;
			total += (double) (q/2) * p;
			total += (double) (q%2) * p;
		} else if(k[0] == 'Y') {
			p = Price.find(k)->second;
			q = Quantity.find(k)->second;
			total += (double) (q/2) * (p * 1.5);
			total += (double) (q%2) * p;
		} else {
			total += (double) Price.find(k)->second * Quantity.find(k)->second;
		}
	}
	printf("%.1f\n", total);
	return 0;
}
