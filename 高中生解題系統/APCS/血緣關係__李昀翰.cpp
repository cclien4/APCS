#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define MAXN 100005
vector<int> G[MAXN];    //Adjacency List
int d[MAXN];    //Distance
bool visited[MAXN];

void dfs(int x, int dis)
{
    d[x] = dis;
    visited[x] = true;
    for(int i=0;i<G[x].size();i++)
    {
        if(!visited[G[x][i]]) dfs(G[x][i], dis+1);
    }
}

int main()
{
    int n;
    while(scanf("%d", &n)==1)
    {
        //Scan Input
        for(int i=0;i<n-1;i++)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            G[a].push_back(b);
            G[b].push_back(a);
        }
        //1st DFS
        dfs(0, 0);
        //Find the index of the furthest vertex
        int max_d = 0, index = -1;
        for(int i=0;i<n;i++) max_d = max(max_d, d[i]);
        for(int i=0;i<n;i++) if(d[i]==max_d) {index = i; break;}
        //Prepare for 2nd DFS
        for(int i=0;i<n;i++) {visited[i]=false; d[i]=0;} max_d = 0;
        //2nd DFS
        dfs(index, 0);
        for(int i=0;i<n;i++) max_d = max(max_d, d[i]);
        //Found answer
        printf("%d\n", max_d);
        //Reset
        for(int i=0;i<n;i++) {G[i].clear(); d[i]=0;visited[i]=false;}
    }
    return 0;
}

