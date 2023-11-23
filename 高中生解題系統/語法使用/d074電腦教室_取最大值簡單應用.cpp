#include <iostream>
using namespace std;

int main(void)
{
	int n,max;
	int a,i;
	
	while(cin>>n)
	{
		max=0;
		for(i=0;i<n;i++)
		{
			cin>>a;
			if(a>max)
			   max=a;
		}
		cout<<max<<endl;
	}
}
