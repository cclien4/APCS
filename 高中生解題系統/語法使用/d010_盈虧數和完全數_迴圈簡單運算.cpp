#include <iostream>
using namespace std;

int main(void)
{
	int n,total=0;
	int i;
	while(cin>>n)
	{
		total=0;
		for(i=1;i<n;i++)
			if(n%i==0)
				total=total+i;
			
		if(total>n)
			cout<<"盈數";
		else if(total==n)
			cout<<"完全數";
		else
			cout<<"虧數";
		cout<<endl;
	}
	
	
}
