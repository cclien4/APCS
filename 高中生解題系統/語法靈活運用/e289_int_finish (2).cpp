#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
int main(void){
	set <int> myset;
	set <int>::iterator it;
	vector <int> v;
	vector <int>::iterator it2; 
	int i,n,m;
	int arr[200000];
	int ans;
	int cnt;
	while(cin>>m>>n){
		//reset data
		ans=0;
		cnt=0;
		myset.clear();
		v.clear();
		//input data
		for(i=0;i<n;i++){
			cin>>arr[i];
		}
		//process data
			//input first data
		for(i=0;i<m;i++){
			myset.insert(arr[i]);
			v.push_back(arr[i]);
		}
			//data condition
				//reset data
				i=m;
		while(cnt+m < (n+1)){
			/*     測試資料用 
			cout<<"size"<<myset.size()<<"      ";
			cout<<"cnt"<<cnt<<"i"<<i<<endl;
			cout<<"========set==========="<<endl;
			for(it=myset.begin();it!=myset.end();it++)
				cout<<*it<<endl;	
			cout<<"=======vector============="<<endl;
			for(it2=v.begin();it2!=v.end();it2++)
				cout<<*it2<<endl;
			cout<<"=========================="<<endl;
			*/ 
			if(myset.size()==m){
				ans++;
			}
			//erase vector begin
				v.erase(v.begin());
			//
				it2=find(v.begin(),v.end(),arr[cnt]);
				if(it2!=v.end()){		//代表裡面有相同的元素 set就不要清除 
				}else{					//代表裡面跟沒有跟第一個相同的元素
					 myset.erase(arr[cnt]);
				}
				//新增新的元素近來 
				v.push_back(arr[i]);
				myset.insert(arr[i]);
				//把cnt與i指到下一個元素 
				cnt++;
				i++;
		}
			cout<<ans<<endl;
				
	}//while
} //main
