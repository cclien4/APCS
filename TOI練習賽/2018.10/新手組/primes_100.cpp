#include <iostream>
#include <math.h>
using namespace std;
bool prime[20000000];
 
void eratosthenes()
{
    for (int i=0; i<20000000; i++)
        prime[i] = true;
 
    prime[0] = false;
    prime[1] = false;
 
    for (int i=2; i<20000000; i++)
        if (prime[i])
            // k琌瞯j琌借计i计
            // パ耞讽prime[k]Θミ
            // k瞇籠┮Τ单i借计ㄤ计
            for (int k=(20000000-1)/i, j=i*k; k>=i; k--, j-=i)
                if (prime[k])
                    prime[j] = false;
}


int main(){
    int a,b,n,j,flag,count;
    int nc,i,cnt,na;
    
    eratosthenes();
  cin>>na;
  for(nc=0;nc<na;nc++){
    count=0;
    cin>>a>>b;
    for(n=a;n<=b;n++){
      if (prime[n] ==true ){
        count++;     
      }
    }
    cout << count <<endl;   
  }
}
