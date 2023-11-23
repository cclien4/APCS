#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
vector<int> vec;
	int n,s;
	while(cin>>n){
	for(int i=0; i<n;i++) {
	cin>>s;
	vec.push_back(s);
	}
	
	sort(vec.begin(),vec.end());
	
	for(int i=0;i<vec.size();i++){
    if(i!=vec.size()-1)
    	cout << vec[i]<<" ";
	else
	    cout << vec[i];
	}
	cout<<endl;
	if(vec[0]>=60){
        cout<<"best case"<<endl;
        cout<<vec[0]<<endl;
    }
    else if(vec[vec.size()-1]<60){
         cout<<vec[vec.size()-1]<<endl;
         cout<<"worst case"<<endl;
        
    }
    else{
    	for(int i=1;i<vec.size();i++){
    		if( vec[i-1] < 60 && vec[i]>=60   )
    		{
    			cout<<vec[i-1]<<endl;
    			cout<<vec[i]<<endl;
    		}
    	}
     }
//	system("pause");
	return 0;
}
}
