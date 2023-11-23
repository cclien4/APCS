#include<cstdio>
const int N = 3000 + 5;
typedef long long ll;
const ll inf = 1000000000 + 1;

int n, len = 0;
ll u, sum[N][N]={0};

int main()
{
	scanf("%d%lld", &n, &u);
	for(int i=1; i<=n; ++i)
	{
		for(int j=1; j<=n; ++j)
		{
			scanf("%lld", &sum[i][j]);
			if(sum[i][j] == -1) sum[i][j] = inf;
			sum[i][j] += sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
		}
	}
	for(int i=0; i<n; ++i)
	{
		for(int j=0; j<n; ++j)
		{
			for(int k=len+1; i+k<=n && j+k<=n && sum[i+k][j+k]-sum[i+k][j]-sum[i][j+k]+sum[i][j]<=u; ++k)
			{
				len = k;
			}
		}
	}
	printf("%d\n", len*len);
	return 0;
}
