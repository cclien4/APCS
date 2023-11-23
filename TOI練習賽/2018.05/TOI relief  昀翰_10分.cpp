#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAXN 100005
using namespace std;
int N;
int t[MAXN];

int main()
{
    while(scanf("%d",&N)==1) {
        for(int i=0;i<N;i++) cin>> t[i];
        if(N==1) {printf("%d\n", t[0]); continue;}
        int ans = 0;
        sort(t, t+N);
        for(int i=1;i<N;i++) ans+=(t[0] + t[i]);
        ans -= t[0];
        printf("%d", ans);
    }
    return 0;
}
