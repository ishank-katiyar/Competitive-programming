#include <bits/stdc++.h>

using namespace std;

int main() 
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  map <int64_t, int> mp;
  for (int i = 1; i <= 10000; i++) {
    mp[i * i] = i;
  }
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    bool ok = true;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      ok &= mp.count (x);
    }
    cout << (!ok ? "YES" : "NO") << '\n';
  }
  return 0;
}
