#include <iostream>
using namespace std;

int main()
{
    int n;
    
    while(cin>>n)
    {
        if(n % 400== 0)
          cout<<"�|�~"<<endl;
        else if(n%100==0)
          cout<<"���~"<<endl;
        else if(n%4==0)
          cout<<"�|�~"<<endl;
        else
          cout<<"���~"<<endl;
                 
    }
}
