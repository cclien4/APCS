#include <iostream>
using namespace std;
int n,m,flag;
void timem(int i,int now,bool up){
	if(up)
		now=now+2*i-1;
	else
		now=now-(2*i-1);
	if(flag==0)
        return;
	if(now==m){
		flag=1;
		return;
    }
	if((now+2*(i+1)-1)<n)
       timem(i+1,now,true);
	if((now-(2*(i+1)-1))>0)
       timem(i+1,now,false);
	
}
int main(void){
	int i,now,c;
	cin>>n>>m;
	i=1;
	now=0;
	timem(i,now,true);
	if(flag)
		cout<<"We can save the world!!";
	else
		cout<<"No!!";
	
	return 0;
}
