#include <stdio.h>
#include <iostream>
using namespace std;

int main(void){
    int N,NO;
    int S[20],i;
    //reset array
    for(i=0;i<20;i++)
       S[i]=1;
       
    cin>>N;
    for(i=0;i<3;i++){
        cin>>NO;
        S[NO-1]=0;
    }   
    for(i=N-1;i>=0;i--){
       if(S[i]==1)
       cout<<"No."<<i+1;
    }
   // system("pause");
}
