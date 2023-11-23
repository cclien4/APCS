#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main(void){
    int N,T;
    int day,cnt;
    int cntT;
    while(cin>>N>>T){
        day=1;
        cntT=N;
        while(cntT<T){
           cntT=cntT*2;
           cntT=cntT+N;
           day++;
         //  cout<<"day"<<day<<"num"<<cntT<<endl;
        }
        if(T==0)
        cout<<0<<endl;
        else
        cout<<day<<endl;
    }
}
