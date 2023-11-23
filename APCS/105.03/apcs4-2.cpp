#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
vector <ll> tree[100004];
ll h[100004];
ll N = 0;
void dfs(ll node,ll par){
  for (auto i:tree[node]){
        if (i != par){
            h[i] = h[node]+1;
            dfs(i, node);
        }
    }
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll n;
  while(cin>>n){
    for(int i=0;i<n;i++){
      tree[i].clear();
    }
    fill(h,h+n+1,0);
    for(ll i=1;i<=n-1;i++){
      ll a,b;
      cin>>a>>b;
      tree[a].push_back(b);
      tree[b].push_back(a);
    }
    dfs(0,-1);
    int maxnode=-1;
    for(int i=0;i<=n-1;i++){
      if(h[i]>maxnode){
        maxnode=h[i];
        N=i;
      }
    }
    fill(h,h+n+1,0);
    dfs(N,-1);
    maxnode=-1;
    for(int i=0;i<n;i++){
      if(h[i]>maxnode){
        maxnode=h[i];
      }
    }
    cout<<maxnode<<endl;
  } 
}
