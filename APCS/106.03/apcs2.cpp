#include <iostream>

using namespace std;

int main(void)
{
    int n,i,cnt=0,mark=0,ptr=0;  //ptr表示目前進行的進度 
    cin >>n;
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
           while(a[mark]!=ptr)   //ptr  = 0
           {
             mark=a[mark];
             m[mark]=1;
           }
           cnt++;
           
           for(i=0;i<n;i++)
              cout<<m[i]<<" ";
            cout<<cnt<<"cnt"<<endl;
            
           while(m[ptr+1]==1 && ptr+1!=n) //被mark過的可先拿掉 
           {
              ptr++;
           }
           ptr++;
                 
    }
    cout<<cnt<<endl;
    
    system("pause");    
}
