#include <iostream>
using namespace std;

int main(void)
{
    int n,i;
    
    do
    {
        cin>>n;
        for(i=1;i<n;i++)
           if(i%7!=0)
          cout<<i<<" ";
        cout<<endl;
    }while(n!=0);
    return 0;
}
