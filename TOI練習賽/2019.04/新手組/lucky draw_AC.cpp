#include <iostream>
using namespace std;
int main(void){
    int A[10000];
    int n,i,b;
    int A_count;
    
    cin>>n;
    //reset array
    for(i=0;i<10000;i++)
      A[i]=0;
      //input array
    for(i=0;i<n;i++)
       cin>>A[i];
    
    A_count=0;
    b=A[n-1];
    //compute a_count
    for(i=0;i<n;i++){
        if((i+1)%b ==1)
          A_count=A_count+A[i];
    }
   // cout<<A_count<<endl;
    i=A_count%n;
    
    if(i==0)
    cout<<n<<" "<<A[n-1]<<endl;
    else
    cout<<i<<" "<<A[i-1]<<endl;
   // system("pause");
    
}
