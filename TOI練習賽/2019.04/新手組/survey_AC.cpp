#include <iostream>
#include <algorithm>
using namespace std;
int main(void){
	long long int n;
	int num[10],num2[10];
	int i,j;
	cin>>n;
	 //reset array
    for(i=0;i<10;i++)
      		num[i]=0;
      		
	while(n!=0){
		num[n%10]++;
		n=n/10;
	}
	
	for(i=0;i<10;i++)
		num2[i]=num[i];
      	//	cout<<num[i];
	//cout<<endl;
	sort(num,num+10);
	for(i=9;i>=0;i--){
		if(num[i]==0)
				break;
		for(j=0;j<=9;j++){
			if(num[i]==num2[j]){
				if(j!=9)
				cout<<j<<" ";
				else
				cout<<j;
				num2[j]=0;
			}
		}
	}

	//system("pause");
}
