#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int n, d;
  cin >> n >> d;
  int cnt = 0, sum = 0;
  for (int i = 0; i < n; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    int ma = max(a, max(b, c));
    int mi = min(a, min(b, c));
    if (ma - mi >= d) {
      cnt++;
      sum += a + b + c;
    }
  }
  cout << cnt << ' ' << sum / 3 << endl;
  return 0;
}
