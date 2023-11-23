#include <iostream>
using namespace std;
int main(void){
    int i,N,T;
    int X[40];
    bool flag=true;
    cin>>N;
    for(i=1;i<=N;i++){
        cin>>X[i];
    }
    cin>>T;
    while(flag){
        if(T==1){//邊界狀態
            if((X[T]-X[T+1])<0)
                flag=false;
            else
                T=T+1;//往右邊滑
        }else if(T==N){//邊界狀態
            if((X[T]-X[T-1])<0)
                flag=false;
            else
                T=T-1;//往左邊滑
        }else{//非邊界狀態
            if((X[T]-X[T-1])<0 && (X[T]-X[T+1])<0)
                flag=false;
            else if((X[T]-X[T-1])>(X[T]-X[T+1])){
                X[T]=100000;//避免再滑回來
                T=T-1;//往左邊滑
            }
            else{
                X[T]=100000;//避免再滑回來
                T=T+1;//往右邊滑
            }

        }

    }
    cout<<T<<endl;
}
