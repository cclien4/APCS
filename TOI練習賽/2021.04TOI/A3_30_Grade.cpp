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
        if(T==1){//��ɪ��A
            if((X[T]-X[T+1])<0)
                flag=false;
            else
                T=T+1;//���k���
        }else if(T==N){//��ɪ��A
            if((X[T]-X[T-1])<0)
                flag=false;
            else
                T=T-1;//�������
        }else{//�D��ɪ��A
            if((X[T]-X[T-1])<0 && (X[T]-X[T+1])<0)
                flag=false;
            else if((X[T]-X[T-1])>(X[T]-X[T+1])){
                X[T]=100000;//�קK�A�Ʀ^��
                T=T-1;//�������
            }
            else{
                X[T]=100000;//�קK�A�Ʀ^��
                T=T+1;//���k���
            }

        }

    }
    cout<<T<<endl;
}
