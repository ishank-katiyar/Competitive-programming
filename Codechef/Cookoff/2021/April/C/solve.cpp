#include <bits/stdc++.h>

using namespace std;

int main() 
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  map <int64_t, int64_t> square;
  for (int64_t x = 1; x <= 100000; x++) {
    square[x * x] = x;
  }
  int t;
  cin >> t;
  while (t--) {
    int64_t x, y;
    cin >> x >> y;
    if (square.count (x + y) == 0 || y % 2 == 1) {
      cout << "NO" << '\n';
      continue;
    }
    int64_t so = -1, se = -1;
    y /= 2;
    for (int64_t i = 1; i * i <= (y); i++) {
      if (y % i) {
        continue;
      }
      int64_t f1 = i;
      int64_t f2 = y / i;
      if (f1 * f1 + f2 * f2 == x) {
        so = f1, se = f2;
        break;
      } 
    }
    if (so == -1 && se == -1) {
      cout << "NO" << '\n';
      continue;
    }
    se -= 1;
    // cout << so << ' ' << se << '\n';
    cout << "YES" << '\n';
    cout << square [x + 2 * y] << '\n';
    int u = 1, v = 2;
    while (so--) {
      cout << u << ' ' << v << '\n';
      v += 1;
    }
    u = 2;
    while (se--) {
      cout << u << ' ' << v << '\n';
      v += 1;
    }
  }
  return 0;
}
