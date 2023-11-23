#include <cstdio>
#include <iostream>
using namespace std;
int d[16];

double M5(int n) {
    return (double) ((d[n-4]+d[n-3]+d[n-2]+d[n-1]+d[n]) / (double)5.0);
}

double M10(int n) {
    return (double) ((d[n-9]+d[n-8]+d[n-7]+d[n-6]+d[n-5]+d[n-4]+d[n-3]+d[n-2]+d[n-1]+d[n]) / (double)10.0);
}

bool A(int n) {
    return M5(n) > M5(n-1);
}

bool B(int n) {
    return M10(n) > M10(n-1);
}

bool C(int n) {
    return ((double)d[n] > M5(n) && M5(n) > M10(n) );
}

bool D(int n) {
    return ((double)d[n]) < (double)1.2 * M10(n);
}

bool E(int n) {
    return ((double)d[n]) > (double)1.2 * M10(n);
}

bool F(int n) {
    return ((double)d[n] < M5(n) && M5(n) < M10(n) );
}

bool G(int n) {
    return M10(n)*1000.0 < M10(n-1)*1000.0;
}


int main() {
    while(scanf("%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d",&d[1],&d[2],&d[3],&d[4],&d[5],&d[6],&d[7],&d[8],&d[9],&d[10],&d[11],&d[12],&d[13],&d[14],&d[15]) == 15) {
        for(int i=11;i<=15;i++) {
            if(i!=11) putchar(' ');
            printf("%d", d[i]);
            if(A(i) && B(i) && C(i) && D(i)) {
                putchar('B');
                continue;
            } else if (E(i) || F(i) || G(i)) {
                putchar('S');
                continue;
            } else {
                putchar('N');
            }
        }
        putchar('\n');
    }
    return 0;
}
