#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str;
	getline(cin, str);
	int count[26] = {};
	for(int i=0; i<str.size(); i++)
	{
		count[str[i]-'A'] += 1;
	}
	for(int i=100; i>0 ; i--)
	{
		for(int j=0; j<26; j++)
		{
			if(count[j]==i) cout<<(char)(j+'A');
		}
	}
	cout<<endl;
}
