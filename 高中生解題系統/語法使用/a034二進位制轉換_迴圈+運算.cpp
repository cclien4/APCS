#include <iostream> 
using namespace std;

int main(void)
{
	int a;
	int b[100],i=0,cnt=0;
	while(cin>>a)
	{
		while(a!=0)
		{
			b[cnt]=a%2;
			a=a/2;
			cnt++;
		}
	//	cout<<cnt<<endl;
		for(i=cnt-1;i>=0;i--)
		{
			cout<<b[i];
		}
		cnt=0;
		cout<<endl;
	} 
	
	
	return 0;
}
