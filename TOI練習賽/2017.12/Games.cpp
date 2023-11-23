#include <iostream>
#include <set>
#include <map>
#include <stack>
#include <vector>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	set<int> mset;
    set<int>::iterator itl,it;
    
    vector<pair<int, int> > vpos;
    vector<pair<int, int> > ::iterator it2;
    
    vector<int> vans; 
    int n,len,j;
    int i,index;
    int m;//monster
  //  while(cin>>n){
    cin>>n;
    		vpos.clear();
 			mset.clear();
 			vans.clear();
 			vpos.push_back(pair<int,int>(1,9999999));
       for(i=0;i<n;i++){
       				cin>>m;
	        		itl=mset.lower_bound(m);
	        		mset.insert(m);
	        		index = distance(mset.begin(), itl);
	        		vpos.push_back(pair<int,int>(index,m)); //紀錄pos位置 
	        		if(itl != mset.end()){  //清除 換掉潛力大的 	
	        			mset.erase(itl);		  
					}
	  	}
			for (it2=vpos.begin(); it2!=vpos.end(); ++it2){
				cout << it2->first << " => " << it2->second << endl;
			}
	   		cout<<mset.size()<<endl;
	   		j=0;
			for (it2=vpos.end(); it2!=vpos.begin(); it2--){ 
	        	if(   it2->first == mset.size()-j){
	        		vans.push_back(it2->second);
	        		j++;
				}
			}
		for(i=vans.size()-1;i>=0;i--){
			if(i!=0)
			   cout << vans[i] << " ";
			else
				cout<< vans[i];
		}
			 cout<<endl; 
   // }
    return 0;
}
