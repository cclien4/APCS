#include<bits/stdc++.h>
std::vector<int> Edge[1000005];
long long R[1000005]={1};
void DFS(int cur)
{
    int n=Edge[cur].size();
    for(int i=0;i<n;i+=1)
    {
        if (R[Edge[cur][i]]==0)
            DFS(Edge[cur][i]);
        R[cur]+=R[Edge[cur][i]];
    }
}
int main()
{
    int S,E;
    std::cin>>S>>E;
    for(int i=0;i<E;i+=1)
    {
        int t1,t2;
        std::cin>>t1>>t2;
        Edge[t2].push_back(t1);
    }
    DFS(S-1);
    std::cout<<R[S-1]<<std::endl;
}
