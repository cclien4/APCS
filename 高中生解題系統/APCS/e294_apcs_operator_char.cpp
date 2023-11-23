#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <cstdlib>
using namespace std;

long long mmax(string a){
	int i,j;
	long long z;
	i=0;
	while( i < a.size()){ //尋找最大位數的偶數
		if(a[i]=='0'){            //當遇到0的時候 不能進行除法 避免造成錯run-time 錯誤
			a[i]=int(a[i])+1;
			for(j=i+1;j<a.size();j++){  //30444 ==> 31111
				a[j]='1';
			}
			break;
		}else if(int(a[i])%2==0){
			a[i]=int(a[i])+1;
			for(j=i+1;j<a.size();j++){  //34211 ==> 35111
				a[j]='1';
			}
			break;
		}else{
			i++;
		}

	}
	//cout<<"after a"<<a<<endl;
	z=stol(a);
	return z;
}

long long mmin(string a){
	int i,j;
	long long z;
	i=0;
	while( i < a.size()){ //尋找最大位數的偶數
		if(a[i]=='0'){            //當遇到0的時候 不能進行除法 避免造成錯run-time 錯誤
		//	a[i]='9';
			if(a[i-1]!='1')             //35001 =>33999
				a[i-1]=int(a[i-1])-2;
			else                        //1001 => 999
				a[i-1]=' ';
			for(j=i;j<a.size();j++){  //35001 ==> 33999
				a[j]='9';
			}

			break;
		}else if(int(a[i])%2==0){
			a[i]=int(a[i])-1;
			for(j=i+1;j<a.size();j++){  //34211 ==> 33999
				a[j]='9';
			}
			break;
		}else{
			i++;
		}

	}
//	cout<<"after a"<<a<<endl;
	z=stol(a);
	return z;
}

int main(void){
	long long x,y;
	string n;
	long long z;
	while(cin>>n){
		x=mmax(n);
		y=mmin(n);
		z=stol(n);
	//	cout<<"x"<<x<<endl;
	//	cout<<"y"<<y<<endl;
		cout<<min(x-z,z-y)<<"\n";
	}


}
