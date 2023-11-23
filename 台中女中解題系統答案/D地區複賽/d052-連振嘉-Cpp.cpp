#include<iostream>
#include<cstdlib>

using namespace std;
int main(){
	char c[201], cc;
	int count[26] = {0}, i = 0, temp;
	cin.getline(c, 200);
	while(c[i]!='\0'){
		if(c[i]-'A'>=0){
			temp = c[i]-'A';
			if(temp>=26){
				temp = temp-32;
			}
			count[temp]++;
		}
		i++;
	}
	for(int i = 0; i < 26; i++){
		cc = 'A'+i;
		cout << cc << ' ';
	}
	cout << endl;
	for(int i = 0; i < 26; i++){
		cout << count[i] << ' ';
	}
	return 0;
}
