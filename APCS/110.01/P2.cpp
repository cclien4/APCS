#include <climits>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

const int NMAX = 50;
const int MMAX = 50;

int S[NMAX][MMAX];
int A[MMAX][MMAX];

int main() {
  int N, M, K;
  cin >> N >> M >> K;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> S[i][j];
    }
  }
  int ans = INT_MAX;
  for (int k = 0; k < K; k++) {
    memset(A, 0, sizeof(A));
    for (int i = 0; i < N; i++) {
      int p;
      cin >> p;
      for (int j = 0; j < M; j++) A[p][j] += S[i][j];
    }
    int sum = 0;
    for (int i = 0; i < M; i++) {
      for (int j = 0; j < M; j++) {
        if (i == j) {
          sum += A[i][j];
        } else if (A[i][j] <= 1000) {
          sum += A[i][j] * 3;
        } else {
          sum += A[i][j] * 2 + 1000;
        }
      }
    }
    ans = min(ans, sum);
  }
  cout << ans << endl;
  return 0;
}
