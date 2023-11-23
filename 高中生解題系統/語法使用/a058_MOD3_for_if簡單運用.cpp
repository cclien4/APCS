#include <iostream>
using namespace std;

int main(void)
{
    int a=0,a1=0,a2=0;
    int i,n,in;
    
    cin>>n;
    for(i=0;i<n;i++)
    {
       cin>>in;
       if(in%3==0)
            a++;
       else if(in%3==1)
            a1++;
       else
            a2++;
            
    }
    cout<<a<<" "<<a1<<" "<<a2<<endl;
    
}
 
