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
	//multiset<int> mset;
    //multiset<int>::iterator itl,it;
           
    vector<pair<int, int> > vpos;
    vector<pair<int, int> > ::iterator it2;
    vector<int> mset;
    //stack<int> sans;
    vector<int> vans; 
    int n,len,j;
    int i,index;
    int m;//monster
    bool flag=0;
    while(cin>>n){
    		vpos.clear();
 			vans.clear();
 			mset.clear();
 			vpos.push_back(pair<int,int>(1,9999999));
       for(i=0;i<n;i++){
       		cin>>m;
                    if(i==0){
                    	mset.push_back(m);
                    	vpos.push_back(pair<int,int>(1,m));
					}
                    else{
                    	for(j=0;j<mset.size();j++){
                    		if(mset[j]>=m){
                    			flag=1;
                    			mset[j]=m;
                    			vpos.push_back(pair<int,int>(j+1,m));
                    			break;
							}
						}
						if(flag==0){
					   		mset.push_back(m);
					   		vpos.push_back(pair<int,int>(j+1,m));
						}
						flag=0;
					}
			}
		//test vpos
	//		for (it2=vpos.begin(); it2!=vpos.end(); it2++){
	//			cout << it2->first << " => " << it2->second << endl;
	//		}
     //	//紀錄pos完成，開始進行處理stack動作 
     /*	    j=0; 
	        for (it2=vpos.end(); it2!=vpos.begin()-1; it2--){ 
	        	if(   it2->first == mset.size()-j){
	        	//	cout<<it2->second<<endl;
	        		sans.push(it2->second);
	        		j++;
				}		
	   		}*/
	   		cout<<mset.size()<<endl;
	   		j=0;
			for (it2=vpos.end(); it2!=vpos.begin(); it2--){ 
	        	if(   it2->first == mset.size()-j){
	        		vans.push_back(it2->second);
	        	 //   cout<<it2->second<<" ";
	        		j++;
				}
			}
	   //output 答案 
		   
		/*   while (!sans.empty()){
		   	if(sans.size()==1)
		   		cout << sans.top();
		   	else
				cout << sans.top() << " ";
			sans.pop();
		}*/
		for(i=vans.size()-1;i>=0;i--){
			if(i!=0)
			   cout << vans[i] << " ";
			else
				cout<< vans[i];
		}
			 cout<<endl; 
    }
    return 0;
}
