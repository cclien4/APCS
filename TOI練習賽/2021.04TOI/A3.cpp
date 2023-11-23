#include <iostream>
using namespace std;
int main(void){
    int i,N,T;
    int X[40];
    bool flag=true;
    int RL=0;//1 left 2 right
    cin>>N;
    for(i=1;i<=N;i++){
        cin>>X[i];
    }
    cin>>T;

    if(T==1){
            if((X[T]-X[T+1])<0)
                flag=false;
            else
                RL=2;
    }else if(T==N){//Ãä¬Éª¬ºA
            if((X[T]-X[T-1])<0)
                flag=false;
            else
                RL=1;
    }else if((X[T]-X[T-1])>(X[T]-X[T+1])){
                RL=1;
    }else if((X[T]-X[T-1])<(X[T]-X[T+1])){
                RL=2;
    }
    while(flag){
        if(RL==1){
            if((X[T]-X[T-1])>=0 && T!=1)
                T=T-1;
            else
                flag=false;
        }else{
            if((X[T]-X[T+1])>=0 && T!=N)
                T=T+1;
            else
                flag=false;
        }

    }
    cout<<T<<endl;
}
