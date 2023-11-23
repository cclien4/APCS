#include <iostream>
using namespace std;
//反轉後的0要略過 

int main(void)
{
    int n,a;
    int flag=0;
    while(cin>>n)
    {
         flag=0;
         while(n>=10)
         {
           a=n%10;
           if(a!=0 && flag==0)
               flag=1;
           if(flag==1)
               cout<<a;
           n=n/10;  
         }
         cout<<n;        
         cout<<endl;
                 
    }
    return 0;
}
