#include <iostream>
#include <set>
#include <math.h>
using namespace std;
int main(){
	multiset<int> mmset;
	multiset<int>::iterator it;
	int n;
	int arr,arr2;
	int sum=0,tgt,suma=0,cnt=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr>>arr2;
		if(arr!=arr2){
			sum=sum+arr+arr2;
			suma=suma+arr;
		 	mmset.insert(arr-arr2);
		}
	}
	tgt=sum/2;
	while(suma!=tgt){
		cnt++;
			it=mmset.lower_bound(suma-tgt);
	    	if((suma-tgt)**it>0){
	    		suma=suma-*it;
	    		mmset.erase(it);
			}else{
				cnt=0;
				break;
			}
	}
	cout<<cnt<<endl<<abs(suma-tgt)<<endl;
}

