#include <iostream>
using namespace std;


int main(void)
{
    int h,m;
    
    cin>>h>>m;
    
    if(h>=7 && h<17)
    {
            if(h==7 && m<30)
                    cout<<"Off School"<<endl;
            else
                    cout<<"At School"<<endl;
    }
    else
         cout<<"Off School"<<endl;
         
         return 0;
    
    
}
