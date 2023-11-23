#include <iostream>
#include <algorithm>
using namespace std;
int main(void)

{
    int n,m,cnt;
    int i;
    int x[1000];
    while(cin>>n)
    {
    //     cin>>n>>m;
         for(i=0;i<n;i++)
         {
             cin>>x[i];
         }
         sort(x,x+n);
         for(i=0;i<n;i++)
         {
             cout<<x[i]<<" ";
         }         
         cout<<endl;
        
    }
    
}
