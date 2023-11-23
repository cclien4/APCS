#include <iostream>
using namespace std;
int main(void)

{
    int n,m,cnt;
    int cnt_y;
   // while(!cin.eof())
    while(cin>>n>>m)
    {
    //     cin>>n>>m;
         cnt_y=1;
         cnt=n;
         while(cnt < m ||  cnt==m)
         {
             cnt=cnt+n+cnt_y;
             cnt_y++;
         }
         
         cout<<cnt_y<<endl;
         
    }
    
}
