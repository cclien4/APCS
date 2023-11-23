#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int a,b,c,d,e;

	while(cin>>a>>b>>c)
	//for(i=0;i<n;i++)
	{
		if(b*b-4*a*c>0)
		  cout<<"Two different roots x1="<< (sqrt(b*b-4*a*c)-b )/ (2*a)<<" , x2="<< (-sqrt(b*b-4*a*c)-b ) /(2*a);
		else if(b*b-4*a*c==0)
		  cout<<"Two same roots x="<<(sqrt(b*b-4*a*c)-b )/ (2*a);
		else
		  cout<<"No real root"; 
	}
	return 0;
 }
