// Author: Min-Zheng Shieh
// Method: Random sampling

#include<cstdio>
#include<cstdlib>
#include<map>

using namespace std;

int m[2000][2000];

bool verify(int L, int B, int R, int T, int x)
{
	int cnt=0;
	for(int i = L; i <= R; i++)
		for(int j = B; j <= T; j++)
			if(m[i][j]==x) cnt++;
	return (cnt<<1)>(R-L+1)*(T-B+1);
}

int query(int L,int B,int R,int T)
{
	int ret = -1;
	map<int,int> cnt;
	for(int i = 0; i < 1000; i++)
	{
		int x=L+rand()%(R-L+1), y=B+rand()%(T-B+1);
		cnt[m[x][y]]++;
	}
	for(auto cand: cnt)
	{
		if(cand.second > 340 && verify(L,B,R,T,cand.first))
			ret = cand.first;
	}
	return ret;
}

int main()
{
	int n, q;
	srand(0x19801201);
	for(scanf("%d",&n); n; scanf("%d",&n))
	{
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				scanf("%d",&m[i][j]);
		scanf("%d",&q);
		for(int i = 0; i < q; i++)
		{
			int L,R,B,T;
			scanf("%d%d%d%d",&L,&R,&B,&T);
			printf("%d\n",query(L,B,R,T));
		}
	}
	return 0;
}
