#include <iostream>   // std::cout
#include <string>     // std::string,
#include <sstream>
using namespace std;
string adds(int x){
	string str;
	stringstream ss;
	int cnt=1;
	while(str.size()<x){
		str="";
		for(int j=1;j<=cnt;j++){		
			ss << j;
			str = ss.str();
		}	
		cnt++;
	}
	return str;
}
int main(){
	int  x,i,n;
	string ans;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>x;
		ans="";
		ans=adds(x);
		cout<<ans<<endl;
		cout<<ans[x-1];
	}
	return 0;
}
