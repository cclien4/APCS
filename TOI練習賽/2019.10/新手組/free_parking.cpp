#include <iostream>
#include <vector>
using namespace std;

int  main(void){
	vector <int> v;
	int i,j,k,n,A,B,C;
	int flag;
	cin>>n;
	for(k=0;k<n;k++){
		cin>>A>>B>>C;
		flag=0;
		v.clear();
		for(j=A+1;j<B;j++){
			if(j%C!=0){
				//cout<<j<<" ";
				v.push_back(j);
				flag=1;
			} 
		}
		if(v.size()==0)
			cout<<"No free parking spaces.";
		else{
			for(i=0;i<v.size();i++)
				if(i==v.size()-1)
					cout<<v[i];
				else
					cout<<v[i]<<" ";
		}
	//	if(flag==0)
	//		cout<<"No free parking sapces.";
		cout<<endl;
		
	}
	
	return 0;
} 
