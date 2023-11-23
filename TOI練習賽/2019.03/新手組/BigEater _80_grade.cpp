#include <iostream>
using namespace std;
int main(void){
    int N,M,K;
    int M_cnt=0,N_cnt;
    cin>>N>>M>>K;
    N_cnt=N;
    if(N>=32){
      while((N_cnt>=32 && K==0) || (N_cnt>=55 && K==1)){
             if(K==0){
                N_cnt=N_cnt-32;
                K=1;
                if(N_cnt==0)
                cout<<M_cnt<<": Wayne eats an Apple pie, and now he doesn't have money."<<endl;
                else
                cout<<M_cnt<<": Wayne eats an Apple pie, and now he has "<<N_cnt<<" dollars."<<endl;
                M_cnt=M_cnt+M;
             }
             else {
                N_cnt=N_cnt-55;
                K=0;
                if(N_cnt==0)
                cout<<M_cnt<<": Wayne drinks a Corn soup, and now he doesn't have money."<<endl;
                else
                cout<<M_cnt<<": Wayne drinks a Corn soup, and now he has "<<N_cnt<<" dollars."<<endl;
                M_cnt=M_cnt+M;
             }   
      }
    }else{
          cout<<"Wayne can't eat and drink.";
    }
    // system("pause");
  
}
