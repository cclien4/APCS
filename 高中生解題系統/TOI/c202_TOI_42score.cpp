#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	long long num[100];
	int n,i,j,cnt;
	long long ans;
	while(cin>>n){
		for(i=0;i<n;i++)
		   cin>>num[i];
		ans=1;
		sort(num,num+n);
		for(i=1;i<=num[0];i++){
			cnt=0;
			for(j=0;j<n;j++){
				if(num[j]%i==0)
					cnt++;
			}
			if(cnt==n)
				ans=i;
		}
		cout<<ans<<endl;
	}
	
}
