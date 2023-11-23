#include <iostream>
#include <cstdio>
using namespace std;
int T, A[100005], a, b;

//O(sqrt(N))
bool ISP(const int &x) {
     if(x<2) return false;
     for(int i=2;i*i<=x;i++) if(x%i==0) return false;
     return true;
}

int main() {
    scanf("%d",&T);
    for(int i=1;i<=100000;++i) A[i] = A[i-1] + ISP(i);   //O(N*sqrt(N))
    while(T--) {
        scanf("%d%d",&a,&b);
        printf("%d\n", A[b] - A[a-1]);
    }
    system("pause");
    return 0;   
}
