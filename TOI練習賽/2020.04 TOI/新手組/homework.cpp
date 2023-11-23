#include <iostream>
#include <algorithm>
using namespace std;
int main(void){
    int R,A;
    int B;
    while(cin>>R>>A){

        if(A!=R){
                 B=R-A;
                 if(A>B)
                        swap(A,B);
                cout<<A<<"+"<<B<<"="<<R<<endl;
        }
        else{
                B=A-3;
                A=3;
                if(A>B)
                        swap(A,B);
                cout<<A<<"+"<<B<<"="<<R<<endl;
        }
    }
}
