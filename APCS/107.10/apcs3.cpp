#include <iostream>
#include <string>
using namespace std;
int main(){
   string in;
   int i;
   double n,k,k_sum,k_cnt;
   while(cin>>in){
   	cin>>n;
   	k=1;
   	k_sum=0;
   	k_cnt=0;
   	for(i=0;i<in.size();i++){
		if(in[i]=='2')
		   k=k/4;
		else if(in[i]=='1'){
			k_cnt++;
			k_sum=k_sum+k;
		}else if(in[i]=='0'){
			k_cnt++;
		}
		//cout<<i<<k_sum<<endl;
		if(k_cnt==4){
			k=k*4;
		}
	}
//	cout<<k_sum<<endl;
	cout<<n*n*k_sum<<endl;
   }
   return 0;
}
