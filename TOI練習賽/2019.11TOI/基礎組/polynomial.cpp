//很適合STL練習 可看出STL優勢
#include <iostream>
using namespace std;

int main(void){
	int n,i,z;
	int x,y;
	int a[1001],b[1001],flag;
	//reset data
	for(i=0;i<1001;i++){
		a[i]=0;
		b[i]=0;
	}
	flag=0;
	//input data
	for(z=0;z<2;z++){
		cin>>n;
		for(i=0;i<n;i++){
			cin>>x>>y;
			if(flag==0)
				a[x]=y;
			else
				b[x]=y;
		}
		flag=1;
	}
	/*for(i=0;i<4;i++){
		cout<<a[i]<<"    "<<b[i]<<endl;
	}*/
	//add array data
	for(i=0;i<1001;i++){
		a[i]=a[i]+b[i];
	}
	flag=0;
	for(i=1000;i>=0;i--){
		if(a[i]!=0){
			cout<<i<<":"<<a[i]<<endl;
			flag=1;
		}
	}
	if(flag==0)
		cout<<"NULL!"<<endl;
	return 0;
}
