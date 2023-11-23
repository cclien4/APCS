//zero.cpp
#include<cstdio>
#include<vector>
const int N = 100, W = 20000, OFFSET = 10000;
const int MIN = -10000, MAX = 10000;

bool dp[N][W+5] = {0};
char op[N][W+5], ans[N];

int main()
{
	int n, val[N];
	scanf("%d", &n);

	for(int i=0; i<n; ++i)
	{
		scanf("%d", &val[i]);
	}

	dp[n-1][val[n-1]+OFFSET] = true;
	op[n-1][val[n-1]+OFFSET] = '+';

	dp[n-1][-val[n-1]+OFFSET] = true;
	op[n-1][-val[n-1]+OFFSET] = '-';

	for(int i=n-2; i>=0; --i)
	{
		for(int j=MIN+val[i]; j<=MAX-val[i]; ++j)
		{
			if(dp[i+1][j-val[i]+OFFSET])
			{
				dp[i][j+OFFSET] = true;
				op[i][j+OFFSET] = '+';
			}
			else if(i!=0 && dp[i+1][j+val[i]+OFFSET])
			{
				dp[i][j+OFFSET] = true;
				op[i][j+OFFSET] = '-';
			}
		}
	}

	if(dp[0][0+OFFSET])
	{
		printf("1\n");
		for(int i=1, cur_val=-val[0]; i<n; ++i)
		{
			ans[i] = op[i][cur_val+OFFSET];

			if(ans[i]=='+') cur_val -= val[i];
			else cur_val += val[i];
		}
		printf("%d", val[0]);
		for(int i=1; i<n; ++i)
		{
			printf("%c%d", ans[i], val[i]);
		}
		printf("\n");
	}
	else
	{
		printf("0\n");
	}
	return 0;
}
