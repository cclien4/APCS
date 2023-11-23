#include <iostream> 
#include <algorithm>
using namespace std;


int main()
{
	int a[3];
	while(cin>>a[0]>>a[1]>>a[2]){
	
	
	sort(a,a+3);
	
	for(int i=0;i<3;i++)  //test sort
	cout<<a[i]<<" ";
    cout<<endl;
    if(a[0]+a[1]<=a[2])
    	cout<<"No";
	else if(a[0]*a[0]+a[1]*a[1]<a[2]*a[2])
    	cout<<"Obtuse";
	else if(a[0]*a[0]+a[1]*a[1]==a[2]*a[2])
    	cout<<"Right";
	else if(a[0]*a[0]+a[1]*a[1]>a[2]*a[2])
    	cout<<"Acute";
//	system("pause");
       return 0;
    }
}
