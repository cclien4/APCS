#include <bits/stdc++.h>
using namespace std;
 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	string a;
while(getline(cin, a)){
	int count = 0;
	char s[10000]="\0";
	int len = a.length();
	int check = 0;
	for(int i=0;i<len;i++){	
	if(!isalpha(a.at(i)))	check = 0;	
		else
			if(!check){
				count++;
				check = 1;
			}
	}
	cout<<count<<endl;
}
	return 0;
}
