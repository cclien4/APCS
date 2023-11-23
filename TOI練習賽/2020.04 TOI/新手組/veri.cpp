#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main(void){
    int A,A_T;
    while(cin>>A){
                  
    A_T=A;
    int maxa=0,maxb=0;
    int temp;
    while(A>0){
       temp=A%10;
       A=A/10;
       
       if(temp>maxa)
         maxa=temp;
       else if(temp>maxb)
         maxb=temp;
    }
    if((maxa*maxa+maxb*maxb)==A_T%1000)
       cout<<"Good Morning!"<<endl;
    else
       cout<<"SPY!"<<endl;
    }
    //cout<<maxa<<maxb<<endl;
  //  system("pause");
}
