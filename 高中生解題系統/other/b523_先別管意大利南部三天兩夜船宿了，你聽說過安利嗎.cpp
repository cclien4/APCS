#include<bits/stdc++.h>
using namespace std;
int main(){
	vector<string> vec;
	string now;
	char input[10001];
	bool flag=false;
	while(cin.getline(input,10001)){
		now=input;
		for(int i=0;i<vec.size()&&flag==false;i++){
			if(now==vec[i]){
				cout<<"YES"<<endl;
				flag=true;
			}
		}
		if(flag==true){
			flag=false;
		}
		else{
			cout<<"NO"<<endl;
			vec.push_back(now);
		}
	} 
	return 0;
}
