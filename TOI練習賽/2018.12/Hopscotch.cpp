#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
int main(void){
	int S,E;
	int n,cnt=0;  //n���e���Ʀr  �t�Ȥ���W�L�⭿ ���i���U�ӼƦr�[
	int sum=0,sub;
	cin>>S>>E;
	sub=E-S;
	n=1;
	while(sum!=sub){
		sum=sum+n;
		cnt++;
		//cout<<"n"<<n;
		if( (sub-sum) >= (sum+n+1) )
			n=n+1;
		else if( (sub-sum) >= (pow(n,2)+n)/2 )
			n=n;
		else if(n>1)
			n=n-1;

	//	cout<<"\tsum"<<sum<<endl;
		
	}
	
	cout<<cnt<<endl;
	system("pause");
}
