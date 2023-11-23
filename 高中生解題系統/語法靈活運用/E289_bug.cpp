#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
int main(void){
	ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
	set <string> myset;
	set <string>::iterator it;
	multiset <string> myset2;
	long long i,n,m;
	string arr[200001];
	long long ans,cnt,size;
	while(cin>>m>>n){
		//reset data
		ans=0;
		cnt=0;
		myset.clear();
		//input data
		for(i=0;i<n;i++){
			cin>>arr[i];
		}
		//process data
			//input first data
		for(i=0;i<m;i++){
			myset.insert(arr[i]);
			myset2.insert(arr[i]);
		}
			//data condition
				//reset data
		i=m;
		while(cnt+m < (n+1)){
			//     測試資料用
			//cout<<"size"<<myset.size()<<"      ";
			//cout<<"cnt"<<cnt<<"i"<<i<<endl;
			/*cout<<"========set==========="<<endl;
			for(it=myset.begin();it!=myset.end();it++)
				cout<<*it<<endl;
			/*cout<<"=======vector============="<<endl;
			for(it2=v.begin();it2!=v.end();it2++)
				cout<<*it2<<endl;
			cout<<"=========================="<<endl;
			*/
			if(myset.size()==m){
				ans++;
			}
				size=myset2.size();
				myset2.erase(arr[cnt]);
				if(size!=(myset2.size()+1))
					myset2.insert(arr[cnt]);
				else
					myset.erase(arr[cnt]);

					
				//新增新的元素近來 
				myset.insert(arr[i]);
				myset2.insert(arr[i]);
				//把cnt與i指到下一個元素 
				cnt++;
				i++;
		}
			cout<<ans<<endl;
				
	}//while
} //main
