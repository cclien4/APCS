#include <iostream>
#include <algorithm>    // std::swap
#include <vector>       // std::vector
using namespace std;

int main(void)
{
    int n,a[1000];
    int i,j;
    while(cin>>n)
    {
        //input array
         for(i=0;i<n;i++)
             cin>>a[i];
         //bubble sort
         for(i=0;i<n;i++)
         {
            for(j=i+1;j<n;j++)
            {
                if((a[i]%10) > (a[j]%10))
                    swap(a[i],a[j]);
                else if(((a[i]%10) == (a[j]%10)) && (a[i]/10<a[j]/10))
                    swap(a[i],a[j]);
            }
         }
         for(i=0;i<n;i++)
             cout<<a[i]<<" ";
          cout<<endl;  
                 
                 
    }
    return 0;
    
}
