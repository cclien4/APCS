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
             //�̷Ӷ}�l�u�q��Jmap�� 
       		} 
    	it=mmap.begin(); it++;  //���V�ĤG����� 
    	sit=mmap.begin();
    	while(it!=mmap.end()){
    	
    		if(sit->second >= it->second){ //�Ĥ@�ت��p  �������u�q 
    		    mmap.erase(it);
    		    it=sit;
			}else if(sit->second> it->first){ //�������u�q
				sit->second = it ->second; //�������u�q
				mmap.erase(it);
				it=sit;
			}else{   //��s���u�q
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
