#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str;
    cin>>str;

    int max_cnt=0,max_index=0;
    int len=int(str.size());
    for(int i=0;i<len;i+=1)
    {
        int cnt=1,index=len-1;
        while(str[i]+1==str[i+1] && i+1<len)
        {
            cnt+=1;
            if(cnt==2) index=i;
            i+=1;
        }
        if(cnt>=max_cnt)
        {
            max_cnt=cnt;
            max_index=index;
        }
    }

    cout<<max_cnt<<' ';
    for(int i=max_index;i<max_index+max_cnt;i+=1)
    {
        cout<<str[i];
    }
}
