#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	int num=0,buff,maxlis=-1;
	vector <int> lis,lislis;
	cin>>num;
	vector<int>::iterator iter=lis.begin();
	int arr[num][3];
	for(int i=0;i<num;i++){
		cin>>buff;
		//cout<<"scanning "<<buff<<endl;
		bool vecend=true;
		arr[i][0]=buff;
		if(i==0){
			lis.push_back(i);
			arr[i][2]=1;
			continue;
		}
		iter=lis.end();
		iter--;
		if(buff<=arr[*iter][0]){
			//cout<<"SMALLER!!"<<endl;
			while(buff<=arr[*iter][0]&&vecend){
				if(iter==lis.begin()){
					vecend=false;
					continue;
				}
				iter--;
			}
			if(vecend==true) iter++;
			arr[i][2]=arr[*iter][2];
			lis[arr[i][2]-1]=i;
			//cout<<"doing shit, lis.size()="<<lis.size()<<endl;
			buff=lis.size();
			if(maxlis<buff)maxlis=buff;
		}
		else{
			//cout<<"LARGER"<<endl;
			arr[i][2]=lis.size()+1;
			lis.push_back(i);
			
		}
	}
	cout/*<<"the length of lis is "*/<<maxlis<<endl;
	//cout<<"THE LONGEST INCREASING SUBSEQUENCE IS..."<<endl;
	while(num--){
		if(arr[num][2]==maxlis){
		lislis.push_back(num);
		maxlis--;
		}
		if(!maxlis) break;
	}
	iter=lislis.end();
	iter--;
	for(iter;iter!=lislis.begin();iter--){
		cout<<arr[*iter][0]<<" ";
	}
	cout<<arr[*iter][0]<<endl;
	 
	//cout<<"THE THREE ARRAYS ARE...................."<<endl;
	//for(int i=0;i<3;i++){
	//	for(int j=0;j<num;j++){
	//		cout<<arr[j][i]<<" ";
	//	}
	//	cout<<endl;
	//}
	return 0;
}

