#include <iostream>
using namespace std;

int main(){
	int n;
	int i;
	int m[10000];
	const int s0=0,s1=1,s2=2;//s0 initial s1 wait up s2 wait down
	int ans,state;
	while(cin>>n){
		for(i=0;i<n;i++){
			cin>>m[i];
		}
		state=s1;
		ans=0;
		for(i=1;i<n;i++){
			switch(state){
			case s1:
				if(m[i]>m[i-1]){
				state=s2;
				}
				break;
			case s2:
				if(m[i]<m[i-1]){
				state=s1;
				ans++;
				}
				break;
			default:
				state=state;
			}
		}
		cout<<ans<<endl;
	}
	
}
