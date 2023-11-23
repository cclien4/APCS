#include <cstdio>
#include <algorithm>
#define INF (int)2e9
using namespace std;


int main() {
	int N;
	while(scanf("%d", &N) == 1) {
		int x, tot = 0, Min = INF, Max = -INF;
		for(int i=0;i<N;i++) {
			scanf("%d", &x);
			tot += x;
			Min = min(Min, x);
			Max = max(Max, x);
		}
		printf("%.2f\n%d\n%d\n", tot / (double) N, Max, Min);
	}
	return 0;
}
