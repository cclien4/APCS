#include <climits>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int NMAX = 200000;

int N; pair<int, int> P[NMAX];

int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) scanf("%d%d", &P[i].first, &P[i].second);
  sort(P, P + N);
  vector<int> A;
  for (int i = 0; i < N; i++) {
    int x = P[i].second;
    int j = upper_bound(A.begin(), A.end(), x) - A.begin();
    if (j >= A.size()) {
      A.push_back(x);
    } else {
      A[j] = x;
    }
  }
  printf("%d\n", (int)A.size());
  return 0;
}
