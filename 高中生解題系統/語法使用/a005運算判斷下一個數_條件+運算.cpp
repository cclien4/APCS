#include <iostream>
using namespace std;

int main()
{
	int a,b,c,d,e;
	int s;
	int n,i;
	cin>>n;
	//while(cin>>a>>b)
	for(i=0;i<n;i++)
	{
		cin>>a>>b>>c>>d;
		if(d-c==c-b)
		  cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<d+d-c<<endl;
		else
		  cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<d*(d/c)<<endl;  
	}
	return 0;
 }
