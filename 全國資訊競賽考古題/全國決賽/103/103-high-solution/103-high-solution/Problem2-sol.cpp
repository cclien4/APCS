//	Solver: Min-Zheng Shieh
// Expected Running Time: <1 second

#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

void solve(int n)
{
	int ans=0;
	vector<int> r(n);
	for(int i=0; i<n; i++) scanf("%d",&r[i]);
	sort(r.begin(), r.end());
	for(int i=1; i<n; i++){
		if(r[i]<=r[i-1]) ans=i+1;
		r[i]+=r[i-1];
	}
	printf("%d\n",ans);
}

int main()
{
	int n;
	for(scanf("%d",&n); n; scanf("%d",&n)) solve(n);
	return 0;
}
