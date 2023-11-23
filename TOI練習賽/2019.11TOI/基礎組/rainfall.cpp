#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
	int i,j,px,py;
	float x[7],y[4],z;
	float max_x,max_y;
	for(i=0;i<8;i++)
		x[i]=0;
	for(j=0;j<5;j++)
		y[j]=0;
	//input data
	for(i=0;i<7;i++){
		for(j=0;j<4;j++){
			cin>>z;
			x[i]=x[i]+z;
			y[j]=y[j]+z;
		}
	}
	max_x=x[0];max_y=y[0];
	for(i=0;i<7;i++)
		if(x[i]>max_x){
			max_x=x[i];
			px=i;
		}
			
			
	for(j=0;j<4;j++)
		if(y[j]>max_y){
			max_y=y[j];
			py=j;
		}
				
				
	cout<<px+1<<endl;
	if(py==0)
		cout<<"mornning"<<endl;
	else if(py==1)
		cout<<"afternoon"<<endl;
	else if(py==2)
		cout<<"night"<<endl;
	else
		cout<<"early mornning"<<endl;
}
