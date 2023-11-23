#include <bits/stdc++.h>
using namespace std;

int main(){
	int m,s,n;  //input data
	int i,j; //for
	int wt,swt;
	int sum;
	vector <int> w;
	vector <int>::iterator it;
	set <int> sw;
	set <int>::iterator sit;
	vector <int> w_ad;
	vector <int>::iterator adit;
	cin>>m>>s>>n;
	sum=0;
	for(i=0;i<n;i++){
		cin>>wt;
		sum=sum+wt;
		w.push_back(wt);
	}
	if((m-sum) >s ){  //¥»¨Ó´N°÷ 
		cout<<"0\n";
	}else{
		sw.insert(w[0]);
		for(i=1;i<n;i++){
			sit=sw.begin();
			w_ad.clear();
			for(sit=sw.begin();sit!=sw.end();sit++){
				swt=*sit;
			//	cout<<"addd"<<swt+w[i]<<endl;
				w_ad.push_back(swt+w[i]);
			}
			for(j=0;j<w_ad.size();j++)
				sw.insert(w_ad[j]);
			sw.insert(w[i]);						
	}

//	cout<<"===set==="<<endl;
//	for(sit=sw.begin();sit!=sw.end();sit++){		
//			cout<<*sit;
//	}
	sit=sw.lower_bound(s);
	cout<<*sit;
//	cout<<"==========="<<endl;	
		
		
		
	}
	
	
	
	
} 
