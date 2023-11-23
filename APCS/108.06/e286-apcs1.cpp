#include <iostream>
using namespace std;

int main(void){
	int i,j,k;
	int grade;
	int suma=0,sumb=0;
	int flag=0; // 1 mean win 2 mean lose
	for(i=1;i<=4;i++){
		for(j=1;j<=4;j++){
			cin>>grade;
			if(i%2==1)
				suma=suma+grade;
			else
				sumb=sumb+grade;
		}

		if(i==2){
			cout<<suma<<":"<<sumb<<endl;
			if(suma>sumb)
				flag=1;
			else
				flag=2;
			suma=0;
			sumb=0;
		}
	}
	cout<<suma<<":"<<sumb<<endl;
	if(flag==1){
		if(suma>sumb)
			cout<<"Win";
		else
			cout<<"Tie";
	}
	else{
		if(suma>sumb)
			cout<<"Tie";
		else
			cout<<"Lose";
	}
	return 0;
}
