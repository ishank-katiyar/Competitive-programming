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
    vector<int> a (n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    auto f = [&] (int x) -> bool {
      int ret = 0;
      int cnt = 0;
      for (int i = 0; i < n - 1; i++) {
        ret ^= a[i];
        if (ret == x) {
          cnt += 1;
          ret = 0;
        }
      }
      return ((ret ^ a.back()) == x) && cnt > 0;
    };
    bool ok = false;
    int preor = 0;
    for (int i = 0; i < n; i++) {
      preor ^= a[i];
      ok |= f (preor);
    }
    reverse (a.begin(), a.end());
    preor = 0;
    for (int i = 0; i < n; i++) {
      preor ^= a[i];
      ok |= f (preor);
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
  return 0;
}
