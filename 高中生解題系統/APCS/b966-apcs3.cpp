#include <iostream>
#include <set>
#include <map>
using namespace std;

int main(void)
{
  //  set<int> sset,eset;
  //  set<int>::iterator itl,it;
   multimap<int, int > mmap;
   multimap<int, int >::iterator sit,it;	
    int n,st,end,i,s;
    while(cin>>n){
    	s=0;
    	
        for(i=0;i<n;i++){
             cin>>st>>end;
             mmap.insert(pair<int,int>(st,end));
             //依照開始線段放入map中 
       		} 
    	it=mmap.begin(); it++;  //指向第二筆資料 
    	sit=mmap.begin();
    	while(it!=mmap.end()){
    	
    		if(sit->second >= it->second){ //第一種狀況  忽略此線段 
    		    mmap.erase(it);
    		    it=sit;
			}else if(sit->second> it->first){ //延長此線段
				sit->second = it ->second; //延長此線段
				mmap.erase(it);
				it=sit;
			}else{   //更新此線段
			     sit=it; 
			}
    		it++;
		}
    //	for (it=mmap.begin();it!=mmap.end(); it++){
    //		cout<<it->first <<it->second<<endl;
     //   }  
    	for (it=mmap.begin();it!=mmap.end(); it++){
    		s=s+it->second - it->first;
        } 
        cout<<s<<endl;
       mmap.clear();
    }
    return 0;
}
