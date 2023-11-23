#include<iostream>
#include<cmath>          //math
#include<cstdlib>        //abs
using namespace std;  
int main(){
	char a[100000];      //a
	while(cin>>a){
		int b=0,y=0;
		for(int i=0;a[i]!=0;i++){
			if(a[i]=='y'){
				b+=abs(i-y);      //yee      
				y+=3;
			}
		}
		cout<<b<<endl;      //b
		}
	return 0;     //end
}
