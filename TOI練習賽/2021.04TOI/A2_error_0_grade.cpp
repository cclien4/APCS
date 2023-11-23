#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
    int i,mc,n;//mc=money conter
    int bn[2000]={0},d[2000]={0},m[2000]={0};//bn=book number d=day m=money
    int total=0;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>bn[i];
        cin>>d[i];
    }
    mc=0;
    for(i=0;i<n;i++){
        if(d[i]>100){
            total=total+(d[i]-100)*5;
            m[mc]=bn[i];
            mc++;
        }
    }
    sort(m,m+mc);
    //output array
    for(i=0;i<mc;i++){
        if(i!=mc-1)
            cout<<m[i]<<" ";
        else
            cout<<m[i]<<endl;
    }
    cout<<total<<endl;
}
