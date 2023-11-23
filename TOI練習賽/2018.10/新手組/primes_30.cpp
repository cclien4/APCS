#include <iostream>
#include <math.h>
using namespace std;
int main(){
  int a,b,n,j,flag,count;
  int nc,i,cnt,na;
  
  cin>>na;
  for(nc=0;nc<na;nc++){
  //while(cin >> a >> b){
    count=0;
    cin>>a>>b;
    for(n=a;n<=b;n++){
      if (n == 1) continue;
      flag=1;
      j=2;
      while (j<=sqrt(n)){
        if ((n%j)==0) {
          flag=0;
          break;  
        }
        j++;   
      }       
      if (flag != 0){
        count++;     
      }
    }
    cout << count <<endl;   
  }
  return 0;
  //system("pause");
}
