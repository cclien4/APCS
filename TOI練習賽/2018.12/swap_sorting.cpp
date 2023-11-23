#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main(void){
	int i,j,k;
	int N,cnt;
	int num[50];
	cin>>N;
	cnt=0;
	for(i=0;i<N;i++)
	   cin>>num[i];
	   
	for(k=0;k<N-1;k++){
		for(i=0;i<=k;i++){
			for(j=i+1;j<N;j++){
				if(num[j-1]>num[j]){
				cnt++;
				//cout<<num[j-1]<<" "<<num[j]<<endl;
				swap(num[j-1],num[j]);
			}
		}
	}
	}

	cout<<cnt<<endl;
//	system("pause");
return 0;
}
