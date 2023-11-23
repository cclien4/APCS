// Author: Min-Zheng Shieh
// Method: Sparse table
// Complexity: O(N^2)

#include<cstdio>
#include<algorithm>

using namespace std;

int max_st[20][5001], min_st[20][5001];
int seq[5001], w2h[5001]={0};

void init()
{
	for(int w=2; w<=5000; w++)
	{
		int h=0;
		while(w>=(1<<h)) h++;
		w2h[w]=--h;
	}
}

int range_min(int begin, int end)
{
	int h=w2h[end-begin];
	return min(min_st[h][begin],min_st[h][end-(1<<h)+1]);
}

int range_max(int begin, int end)
{
	int h=w2h[end-begin];
	return max(max_st[h][begin],max_st[h][end-(1<<h)+1]);
}

void solve()
{
	int n;
	scanf("%d",&n);
	for(int i = 1; i <= n; i++) scanf("%d",&seq[i]);
	for(int i = 1; i <= n; i++) max_st[0][i] = min_st[0][i] = seq[i];
	for(int h = 0; h < 12; h++)
		for(int i = 1; i <= n; i++)
		{
			int j = min(n,i+(1<<h));
			max_st[h+1][i]=max(max_st[h][i],max_st[h][j]);
			min_st[h+1][i]=min(min_st[h][i],min_st[h][j]);
		}
	int ans=0;
	for(int i = 1; i < n; i++)
		for(int j = i+1; j <= n; j++)
		{
			if(abs(seq[i]-seq[j])==j-i
				&& min(seq[i],seq[j])==range_min(i,j)
				&& max(seq[i],seq[j])==range_max(i,j))
				ans++;
		}
	printf("%d\n",ans);
}

int main()
{
	int ncases;
	init();
	scanf("%d",&ncases);
	while(ncases--) solve();
	return 0;
}
