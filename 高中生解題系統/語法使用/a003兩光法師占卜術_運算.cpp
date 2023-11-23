#include <iostream>
using namespace std;

int main()
{
	int a,b;
	int s;
	while(cin>>a>>b)
	{
		s=(a*2+b) % 3;
		if(s==0)
		  cout<<"´¶³q";
		else if(s==1)
		   cout<<"¦N";
		else
		   cout<<"¤j¦N"; 
	}
	return 0;
 }
