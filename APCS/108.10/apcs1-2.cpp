#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
int mid(int s[],int m){
    int b[]={s[m-3],s[m-2],s[m-1]};
    sort(b,b+3);
    return b[1];
}

int main(void){
    int i,n;
    int arr[33];
   
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
               arr[i]=mid(arr,i);
            }
        }
        //output array
        for(i=0;i<n;i++)
           cout<<arr[i]<<" ";                   
    }
    
}
