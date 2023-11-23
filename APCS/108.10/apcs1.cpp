#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;


int main(void){
    int i,n;
    int arr[33],s[3];
   
    while(cin>>n){
        //reset array
        for(i=0;i<33;i++)
           arr[i]=0;
        //input array
        for(i=0;i<n;i++)
           cin>>arr[i];
        //process array
        for(i=3;i<n;i++){
            if(abs(arr[i]-arr[i-1]) > 5){
               // your code     
               s[0]=arr[i-3];
               s[1]=arr[i-2];
               s[2]=arr[i-1];
               sort(s,s+3);
               arr[i]=s[1];
              // cout<<i<<"ya"<<endl;
            }
        }
        //output array
        for(i=0;i<n;i++)
           cout<<arr[i]<<" ";                   
    }
    
}
