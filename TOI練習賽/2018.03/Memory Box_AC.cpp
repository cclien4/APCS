#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int P,B,M,N;
    int i;
    int N_reg;
    cin>>B;
    for(i=0;i<B;i++){
          cin>>P;
          N_reg=sqrt(P*2);
          while((N_reg*N_reg+N_reg)<= P*2)
             N_reg++;
          N=N_reg;
          M=N*(N+1)/2-P;
          
          if(i!=B-1)
                    cout<<M<<" "<<N<<endl;           
           else
               cout<<M<<" "<<N; 
                     
    }
   // system("pause");
    
}
