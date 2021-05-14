#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    bool ok = true;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      ok &= (a[i] <= d);
    }
    sort(a.begin(), a.end());
    cout << ((a[0] + a[1] <= d || ok) ? "YES" : "NO") << '\n';
  }
  return 0;
}
