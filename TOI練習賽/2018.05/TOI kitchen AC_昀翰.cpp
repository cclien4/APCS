#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#define MAXN 505
#define INF int(1e9)
using namespace std;
int N, M;
string name[MAXN];
int G[MAXN][MAXN];


int main()
{
    while(scanf("%d%d",&N,&M)==2) {
        int ans = int(2e9);
        int ans_v;
        for(int i=1;i<=N;i++)
            for(int j=1;j<=N;j++)
                G[i][j] = INF;

        for(int i=1;i<=N;i++) cin>>name[i];
        for(int i=0;i<M;i++) {
            int a, b, c;
            cin>>a>>b>>c;
            G[a][b] = c;
            G[b][a] = c;
        }
        for(int k=1;k<=N;k++)
            for(int i=1;i<=N;i++)
                for(int j=1;j<=N;j++) {
                    G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
                }
        for(int i=1;i<=N;i++) {
            int tot = 0;
            for(int j=1;j<=N;j++) if(i!=j && G[i][j] != INF) {
                tot += G[i][j];
            }
            if(tot < ans) {
                ans = tot;
                ans_v = i;
            }
        }
        cout<<name[ans_v]<<endl;
    }
    return 0;
}
