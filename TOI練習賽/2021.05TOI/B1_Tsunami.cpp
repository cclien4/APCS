#include <vector>
#include <stdio.h>

int main() {

	long long N, K;
	scanf("%lld%lld", &N, &K);

	std::vector<long long> d(N+1), prefix_sum(N+1);
	for (int i = 1; i <= N; ++i) {
		scanf("%lld", &d[i]);
		prefix_sum[i] = d[i] + prefix_sum[i-1];
	}

	long long l = 0, r = prefix_sum[N];
	while (l != r) {
		long long m = (l + r) / 2, count = 0;

		for (int i = 1, j = 1; i <= N; ++i) {
			while (j <= N && prefix_sum[j]-prefix_sum[i-1] <= m) {
				++j;
			}
			if (prefix_sum[j]-prefix_sum[i-1] > m) {
				count += (N - j + 1);
			}
		}

		if (count < K) {
			r = m;
		}
		else {
			l = m+1;
		}
	}

	printf("%lld\n", l);

}
