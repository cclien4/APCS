#include <cstdio>
#include <algorithm>
#include <set>

const int NMAX = 200000;

int X[NMAX];

int main() {
  int N, L;
  scanf("%d%d", &N, &L);
  for (int i = 0; i < N; i++) {
    int x, p;
    scanf("%d%d", &x, &p);
    X[p - 1] = x;
  }
  long long ans = 0;
  std::set<int> s {0, L};
  for (int i = 0; i < N; i++) {
    auto it = s.insert(X[i]).first;
    ans += *next(it) - *prev(it);
  }
  printf("%lld\n", ans);
  return 0;
}
