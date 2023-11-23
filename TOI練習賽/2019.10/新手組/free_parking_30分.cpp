#include <iostream>
using namespace std;

int  main(void){
	int i,j,n,A,B,C;
	bool flag=false;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>A>>B>>C;
		flag=false;
		for(j=A+1;j<B;j++){
			if(j%C!=0){
				cout<<j<<" ";
				flag=true;
			} 
		}
		if(!flag)
			cout<<"No free parking sapces.";
		cout<<"\n";
		
	}
	
	return 0;
} 
