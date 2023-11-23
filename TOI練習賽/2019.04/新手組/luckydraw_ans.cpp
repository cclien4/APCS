#include <iostream>
using namespace std;
int main()
{
    int n=0;
    cin>>n;
    int num[10005]={};
    for(int i=0;i<n;i+=1){
        cin>>num[i];
    }
    int B=num[n-1];
    int total=0;
    for(int i=0;i<n;i+=1){
        if((i+1)% B==1){
            total += num[i];
        }
    }
    int m=total%n;
    if(m==0) m=n;
    cout<<m<<' '<<num[m-1];
}
