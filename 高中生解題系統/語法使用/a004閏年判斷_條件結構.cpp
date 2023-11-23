#include <iostream>
using namespace std;

int main()
{
    int n;
    
    while(cin>>n)
    {
        if(n % 400== 0)
          cout<<"閏年"<<endl;
        else if(n%100==0)
          cout<<"平年"<<endl;
        else if(n%4==0)
          cout<<"閏年"<<endl;
        else
          cout<<"平年"<<endl;
                 
    }
}
