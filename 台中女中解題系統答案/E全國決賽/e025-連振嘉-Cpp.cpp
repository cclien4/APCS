#include <iostream>
#include <cstdlib>
#include <algorithm>
//�W�ǫ��٬O�|�J�줣�����D�A�̦h�u�ள��80%������ 

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
