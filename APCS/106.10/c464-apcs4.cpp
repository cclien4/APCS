#include <iostream>
#include <map>
#include <bitset>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
//size既然不夠，就已map代替，但發現儲存空間不夠，因此利用map+vector完成 

struct subject
{
  int wei; //weight
  int ff; //f
};


vector<subject> sub;

//map<int,multimap<int,int> > mmap;
//map<int,multimap<int,int> >::iterator it;

//vector <int>wv;
//vector <int>fv;
//vector <int>subject;

int main(void){
    unsigned long long ans;
    int n;   //共幾筆資料 
    int i,j;
    int k,m;
    int w,f;
    
    while(cin>>n){
   //     wv.clear();
    //    fv.clear();
    //    wf.clear();
        //  input data information
        for(i=0;i<n;i++){
            cin>>w;
            //Push back new subject created with default constructor.
    		sub.push_back(subject());
    		//Vector now has 1 element @ index 0, so modify it.
    		sub[i].wei = w;
    
            //sub.wei.push_back(w);
		}   
        for(i=0;i<n;i++){
            cin>>f;
            sub[i].ff = f;
		}
	//	for(i=0;i<n;i++){
    //        wf.push_back(wv[i]*fv[i]);
	//	}
		//output test
		for(i=0;i<n;i++){
            cout<<sub[i].wei;
		}
		//step1  先照f大小排 (影響最大)
		//step2  按照w大小排(影響小)
		//step3  進行偵測 ( 利用最大只有一千 進行總和陣列判別) 

		
    }
}
