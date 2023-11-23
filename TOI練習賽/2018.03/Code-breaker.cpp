#include<iostream> 
#include <math.h>
#include <string>
using namespace std; 
int main() 
{ 
    //char data[1000]; 
    //char data2[1000];
     //  int A1,A2,A3;
     int size;
    int num[1001];
    int num2[1001];
    int num_sum[1001];
    int i,j;
    bool flag=0;
    string data,data2;
    cin>>data;
    cin>>data2;
   //TEST 
  //  cout<<int(data[0])-65;
  //  cout<<data.size()<<endl;
    for(i = data.size()-1 ; i >=0  ; i--) 
        num[i]=int(data[data.size()-i-1])-65;
    //test
    //for(i = 0 ; i <data.size() ; i++) 
    //     cout<<num[i]<<endl;  
    for(i = data2.size()-1 ; i >=0  ; i--) 
        num2[i]=int(data2[data2.size()-i-1])-65;
    //進行累加
        if(data.size()>data2.size()){
            size=data.size();
            for(i = data2.size() ; i < data.size()  ; i++)
                 num2[i] = 0;
        }
        else{
            size=data2.size();
            for(i = data.size() ; i < data2.size()  ; i++)
                 num[i] = 0;
        }
        cout<<size;
    //test
   // for(i = 0 ; i < size  ; i++) 
   //      cout<<num[i]<<" "<<num2[i]<<endl<<endl;
      for(i = 0 ; (i < size) || (flag==1)  ; i++) {
            num_sum[i]=num_sum[i]+num[i]+num2[i];
            if(num_sum[i]>=26){
                               
                num_sum[i+1]=num_sum[i+1]+1;
               // cout<<i+1<<" "<<num_sum[i+1]<<endl;
                num_sum[i]=num_sum[i]-26;
                if(i==size-1)
                   flag=1;
            }
      }
      
      if(flag)
         size++;
      
      //test
    for(i = size-1 ; i >= 0  ; i--) 
     // cout<<num_sum[i]<<endl;
           cout<<  char(num_sum[i]+65); 
    /*
          //本想著按照公式解法，想想最後應該會TLE
          //習慣用一個String，會轉換數字和字串即可    
        cin >> data; 
        for(i = 0; i < 100 && data[i] != NULL; i++) {
            //cout << int(data[i]) << endl;  
            //cout<<i;
               num[i]=int(data[i])-65;
               size=i;
            }
         for(i = 0; i<=size; i++) {
              //   cout<<num[i]<<endl;
              A1=A1+num[i]*pow(26,size-i);
         } 
         cout<<A1;
    
        A3=A1+A2;
        cout<<A3;
         for(i = size; i>=0; i--) {
              num[i]=A3/ 1*pow(26,size);
              A3=A3-num[i];
              cout<<num[i]<<endl;
         } */
    system("pause"); 
    cout<<endl;
    return 0; 
} 
