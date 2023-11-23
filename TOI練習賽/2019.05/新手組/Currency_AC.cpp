#include <iostream>
#include <iomanip>
using namespace std;

int main(void){
	double M,CM;
	char C;
	double FM;
	while(cin>>M){
		cin>>CM;
		cin>>C;
		
		if(C=='T')
			FM=M-CM*1;
		else if(C=='U')
		    FM=M/30.9-CM;
		else if(C=='J')
		    FM=M/0.28-CM;
		else if(C=='E')
			FM=M/34.5-CM;
	
	
	
	    if(FM>=0)
			cout  << C<<" "<<fixed<<setprecision(2) << FM <<endl;
		else
			cout  << "No Money"<<endl;
	}
	
	
}
