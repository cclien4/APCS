#include <iostream>
#include <cstdlib>
#include <algorithm>
//上傳後還是會遇到不明問題，最多只能拿到80%的分數 

using namespace std;

int main(){
    int w, c, n=0, q[50000];
    cin >> w;
    for(int i = 0; i < w; i++){
        cin >> c;
        while(c!=0){
                 if(c==-1){
                       if(n!=0){
                                sort(q, q+n);
                                cout << q[0] << ' ';
                                q[0] = 10001;
                                sort(q, q+n);
                                n--;
                       }
                 }else if(c==-2){
                       if(n!=0){
                                sort(q, q+n);
                                cout << q[n-1] << ' ';
                                n--;
                       }
                 }else{
                       q[n] = c;
                       n++;
                 }
                 cin >> c;   
        }
        n = 0;
        cout << endl;
    }
    return 0;
}
