#include <iostream>
using namespace std;


int main(void){
	int a,b,c;
	bool flag;
	while(cin>>a>>b>>c){
		flag=0;
		//cout<<a&&b;
	/*	if(  (a&b) == c ){   80¤À 
			cout<<"AND"<<endl; 
			flag=1;
		}
		if((a|b)==c){
			cout<<"OR"<<endl; 
			flag=1;
		}
		if((a^b)==c){
			cout<<"XOR"<<endl;
			flag=1; 
		}
		if(!flag)
		 cout<<"IMPOSSIBLE"<<endl;*/
		 
		if( ((a!=0) & (b!=0)) == c ){
			cout<<"AND"<<endl; 
			flag=1;
		}
		if( ((a!=0) | (b!=0)) == c ){
			cout<<"OR"<<endl; 
			flag=1;
		}
		if( ((a!=0) ^ (b!=0)) == c ){
			cout<<"XOR"<<endl;
			flag=1; 
		}
		if(!flag)
		 cout<<"IMPOSSIBLE"<<endl;
		 
		 
		 
		 
	}
	
} 
