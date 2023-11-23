#include <iostream>
#include <map>
#include <bitset>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;


struct subject
{
  int wei; //weight
  int ff; //f
  int cost;
};




bool acompare(subject lhs, subject rhs) 
{ 
return lhs.cost < rhs.cost; 
}


int main(void){
    unsigned long long ans;
    int n;   //共幾筆資料 
    int i,j;
    int w,f;
    int total_w;
    subject sub[100000];
    while(cin>>n){
    //	subject.clear();
    for(i=0;i<100000;i++){
    	sub[i].wei=0;
    	sub[i].ff=0;
    	sub[i].cost=0;
    }
    	total_w=0;
    	ans=0;
        //  input data information
        for(i=0;i<n;i++){
            cin>>w;
            //Push back new subject created with default constructor.

    		//Vector now has 1 element @ index 0, so modify it.
    		sub[i].wei = w;
    		total_w=total_w+w;
		}
		// input take times   
        for(i=0;i<n;i++){
            cin>>f;
            sub[i].ff = f;
		}
		// input cost times
		for(i=0;i<n;i++){
            sub[i].cost = (total_w-sub[i].wei) * sub[i].ff;
		}
		//sort cost
		sort(sub,sub+n,acompare);
		//output test
	//	for(i=0;i<n;i++){
    //        cout<<sub[i].wei<<sub[i].ff<<"\tcost="<<sub[i].cost<<endl;
//		}
		
		//compute answer
		for(i=0;i<n;i++){
			ans=ans+  (total_w-sub[i].wei) * sub[i].ff;
			total_w=total_w-sub[i].wei;
		}
		cout<<ans<<endl;
    }
}
