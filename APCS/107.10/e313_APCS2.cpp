#include <bits/stdc++.h>
using namespace std;

int main(){
	vector <string> v;
	vector <string>::iterator it;
	set <char> vs[1000];
	set <char>::iterator sit;
	int i,n,j;
	int mins;
	char xin[1000];
	int len_xin,mint,minj; 
	string ans[1000];
	int ans_cnt;
	cin>>n;
	mins=999;
	//insert data
	for(i=0;i<n;i++){
		cin>>xin;
		len_xin=strlen(xin);
		v.push_back(xin);
		for(j=0;j<len_xin;j++)
		     vs[i].insert(xin[j]);
	} 
	// get size
	mins=999;
	for(i=0;i<n;i++){
		mint=vs[i].size();
		mins=min(mins,mint);
	} 
	//cout<<mins;
	//copy small size
	ans_cnt=0;
	for(i=0;i<n;i++){
		mint=vs[i].size();
		if(mint==mins){
			ans[ans_cnt]=v[i];
			ans_cnt++;
		}
	}
	sort(ans,ans+ans_cnt);
//	for(i=0;i<ans_cnt;i++){
		cout<<ans[0]<<endl;
//	} 
	/*
	cout<<"vvvvvvvvvvvvvv"<<endl;
	for(i=0;i<n;i++){
		for(j=0;j<v[i].size();j++)
			cout<<v[i][j];
		cout<<endl;
	}
	cout<<"================"<<endl;
	for(i=0;i<n;i++){
		for(sit=vs[i].begin();sit!=vs[i].end();sit++)
	    	cout<<*sit;
	    cout<<endl;
	}
	    
//	}*/
	
} 
