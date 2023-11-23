#include <iostream>
using namespace std;

int main(void)
{
    int i,t,n,c=1;
    cin>>t;
   for(i=0;i<t;i++)
   {
      cin>>n;
    while(n/10!=0)
    {
        c=c*(n%10);
        n=n/10;
    }
    c=c*(n%10);
    cout<<c<<endl;
    c=1;
    }
    return 0;
    
    
}
