#include <iostream>

using namespace std;

int main(void)
{
    int n,i,cnt=0,mark=0,ptr=0;  //ptr表示目前進行的進度 
    while(cin >>n){
	
    int a[n],m[n]; //增加mark陣列來表示是否曾經被選過 
    
    for(i=0;i<n;i++)
    {
      cin>>a[i];
      m[i]=0;
    }
    while(n>ptr)
    {
           m[ptr]=1;
           mark=ptr;
           while(a[mark]!=ptr)
           {
             mark=a[mark];
             m[mark]=1;
           }
           cnt++;
           while(m[ptr+1]==1 && ptr+1!=n) //被nark過的可先拿掉 
           {
              ptr++;
           }
           ptr++;
                 
    }
    cout<<cnt<<endl;
	}
    //system("pause");
	return 0;    
}
