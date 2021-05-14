#include <bits/stdc++.h>

using namespace std;

int main() 
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int q;
    cin >> q;
    const int max_bit = 40;
    vector<int> bb (45);
    vector<int64_t> a (n);
    auto f = [&] () -> int64_t {
      int64_t ans = 0;
      for (int i = 0; i <= max_bit; i++) {
        if (bb[i] > 0) {
          ans += (int64_t)1 << i;
        }
      }
      return ans;
    };
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      for (int j = 0; j <= max_bit; j++) {
        if ((a[i] >> j) & 1) {
          bb[j] += 1;
        }
      }
    }
    cout << f () << '\n';
    while (q--) {
      int64_t idx, v;
      cin >> idx >> v;
      idx -= 1;
      for (int j = 0; j <= max_bit; j++) {
        if ((a[idx] >> j) & 1) {
          bb[j] -= 1;
        }
      }
      for (int j = 0; j <= max_bit; j++) {
        if ((v >> j) & 1) {
          bb[j] += 1;
        }
      }
      a[idx] = v;
      cout << f () << '\n';
    }
  }
  return 0;
}
