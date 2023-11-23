#include <iostream>
using namespace std;

int main(void){
    int i,n;
    int h[2000]={0},w[2000]={0};
    int min_i,min;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>h[i];
    for(i=0;i<n;i++)
        cin>>w[i];
    min=999999;
    for(i=0;i<n;i++){
        if(min>h[i]*w[i]){
            min=h[i]*w[i];
            min_i=i;
        }
    }
    cout<<h[min_i]<<" ";
    cout<<w[min_i]<<endl;
}
