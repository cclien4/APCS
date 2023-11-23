#include <iostream> 
using namespace std;

int main(void)
{
	int cnt=0,n;
	int i,s0,s1,s2;
	while(cin>>n){
		i=0;
		cnt=0;
        while(i<n){
        	cin>>s0;
        	if(s0==1){
        		cnt++;
        		if(n-i>2){
        			cin>>s1>>s2;
        			i=i+3;   //s0  s1 s2
				}
        		else if(n-i==2){
        			cin>>s1;
        			i=i+2;   //s0  s1
        		}
        		else if(n-i==1){
        			i=i+1;  //s0
				}
			}else{
				i++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
