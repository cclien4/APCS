#include<bits/stdc++.h>
#include <iostream>
#include <map>
using namespace std;

int main() {
	cin.sync_with_stdio(false), cin.tie(0);
	char input[1005];
	int characters, amount;
	long long answer = 0, have, mask = 0;
	cin >> characters >> amount;
	for (int i = 0; i < characters; ++i)
		mask += (1LL << i);
	map <long long, int> CPset;
	map <long long, int>::iterator iter;
	while (amount--) {
		cin >> input, have = 0;
		for (int i = 0; i != strlen(input); ++i)
			if (input[i] <= 'Z')
				have |= (1LL << (input[i] - 'A'));
			else
				have |= (1LL << (input[i] - 'a' + 26));
		if ((iter = CPset.find(have ^ mask)) != CPset.end())
			answer += iter->second;
		CPset[have]++;
	}
	cout << answer << '\n';
}
