#include <iostream>
#include <bitset>
#include <cmath>
#include <algorithm>
#include <vector> 
#include <bits/stdc++.h> 
using namespace std;
struct subject{
	int num[30];
	int siz;
};

bool print(subject a,subject b){
	int i;
	for(i=0;i<a.siz;i++){
		if(a.num[i]!=b.num[i])
			return a.num[i] < b.num[i];
	} 
	
}

vector<subject> ans;
vector<subject>::iterator v;
int main(void){
	int n,m;
	int i,a[30],b,c;
	int sum;
	bitset<30> k;
	int kc;
	/*////////////////////// 
	a==>10 20 40 80
	k==>0 1 0 1    => sum=>100
	///////////////////////*/
	while(cin>>n>>m){
		kc=0;
		b=0;							//STL�ǲ� 
		for(i=0;i<n;i++){
			cin>>a[i];
		}
		sort(a,a+n);
		while(kc!=pow(2,n)){
			k=kc;
			sum=0;
			for(i=0;i<n;i++){
				sum=sum+a[i]*k[i];
				if(sum>m)
					break;
			}
			c=0;							//STL�ǲ� 
			if(sum==m){
				ans.push_back(subject());  //STL�ǲ� 
				for(i=0;i<n;i++){
					if(k[i]==true){
						ans[b].num[c]=a[i];  //STL�ǲ�  
						c++;				//STL�ǲ� 
					//	cout<<a[i]<<" ";  // �D�D�ةҭn  ��mSTL���s�s�� 
					}
				}
				ans[b].siz=c;				//STL�ǲ� 
				b++;						//STL�ǲ� 
				//cout<<endl;	
			}
			kc++;
		}
	//	cout<<"================="<<endl;
		sort(ans.begin(),ans.end(),print);	//STL�ǲ� 
		for(v = ans.begin() ; v != ans.end() ; v++){	//STL�ǲ� 
			for(i=0;i<(*v).siz;i++)
      			cout<<(*v).num[i]<<" ";
      		cout<<endl;
  		}
		/*for(i=0;i<b;i++){
			for(c=0;c<ans[i].siz;c++)
				cout<<ans[i].num[c]<<" ";
			cout<<endl;
		}*/
		
		
	}
	
} 
