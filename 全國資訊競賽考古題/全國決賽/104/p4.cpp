// Author: Min-Zheng Shieh

#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

const int MAXN=200;
const int MAXK=200;
int c[MAXN], last[MAXK+1], next_pos[MAXN];
int dp[MAXN][MAXN];

inline void init(int n, int k)
{
	for(int i = 0; i <= k; i++) last[i]=n;
	for(int i = 0; i < n; i++)
		for(int j = i; j < n; j++)
			dp[i][j]=0;
}

int ans(int L, int R) // [L,R]
{
	if(L>R) return 0;
	if(dp[L][R]) return dp[L][R];
	dp[L][R]=1+ans(L+1,R);
	for(int x=next_pos[L]; x <= R; x=next_pos[x])
		dp[L][R]=min(dp[L][R],ans(L+1,x-1)+ans(x,R));
	return dp[L][R];
}

void solve()
{
	int n, k;
	scanf("%d%d",&n,&k);
	init(n,k);
	for(int i = 0; i < n; i++) scanf("%d",&c[i]);
	for(int i = n-1; i >= 0; i--)
	{
		next_pos[i]=last[c[i]];
		last[c[i]]=i;
	}
	printf("%d\n",ans(0,n-1));
}

int main()
{
	int ncases;
	scanf("%d",&ncases);
	while(ncases--) solve();
	return 0;
}
