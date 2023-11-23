//#include<bits/stdc++.h>
#include <iostream>
#include <cmath>
#define ll long long
#define INF 0x3f3f3f3f
#define pb push_back
#define pii pair<int,int>
#define mem(x) memset((x),0,sizeof((x)))
//#define AC ios_base::sync_with_stdio(0), cin.tie(0)
using namespace std;
int main(){
  //  AC;
  
    ll a,b,m,n,i,T;
    cin>>a>>b;
    n=sqrt(b-a);
    i=b-a;
    m=n*n;
    i-=m;
    if(i>n) cout<<2*n+1<<endl;
    else cout<<2*n<<endl;
    system("pause");
}
