#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define MAXN 100005
int p[MAXN];    //Array to record parent vertex
vector<int> ch[MAXN]; //Adjacency Vertex to record child vertices
int h[MAXN]; //The height of each vertex
int n;  //Number of vertices

int find_rt(int x)  //Find the root of x
{
    return (x==p[x])?x:find_rt(p[x]);
}

void solve_height()
{
    vector<int> leaves;
    for(int i=1;i<=n;i++)
    {
        if(ch[i].size()==0) leaves.push_back(i);
    }
    for(int i=0;i<leaves.size();i++)
    {
        int k = leaves[i]; h[k] = 0;
        while(k!=p[k])
        {
            h[p[k]] = max(h[p[k]], h[k] + 1);
            k = p[k];
        }
    }
}

int main()
{
    while(scanf("%d", &n)==1)
    {
        //Initialize
        for(int i=1;i<=n;i++)
        {
            h[i] = 0;
            ch[i].clear();
            p[i] = i;
        }
        //Scan input
        for(int i=1;i<=n;i++)
        {
            int k; scanf("%d", &k); //Vertex i has k child vertices
            for(int j=1;j<=k;j++)
            {
                int child; scanf("%d", &child);
                ch[i].push_back(child);
                p[child] = i;
            }
        }
        //Solve
        solve_height();
        long long h_sum = 0;
        for(int i=1;i<=n;i++) h_sum += h[i];
        printf("%d\n%lld\n", find_rt(1), h_sum);
    }
    return 0;
}

