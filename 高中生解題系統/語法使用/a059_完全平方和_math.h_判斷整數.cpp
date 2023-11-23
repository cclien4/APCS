#include <iostream>
#include <math.h>
using namespace std;
int main(void)
{
    int n,a,b;
    int i,j,total=0;
    float c;
    cin>>n;
    for(i=0;  i<n;i++)
    {
        cin>>a>>b;
        for(j=a;j<=b;j++)
        {
             c=sqrt(j);
             if(c-int(c)==0)
                total=total+j;    
        }
        cout<<"Case "<<i+1<<": "<<total<<endl;
        total=0;
    }
      
    
}
