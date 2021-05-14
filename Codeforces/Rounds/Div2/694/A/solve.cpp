#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int64_t n, x;
  cin >> n >> x;
  vector<int64_t> a (n);
  int64_t mn = 0, mx = 0;
  for (int i = 0; i < n; i++) {
   cin >> a[i];
   mn += (a[i] / x) + (a[i] % x == 0 ? 0 : 1);
   mx += a[i];
  }
  int64_t a1 = mn;
  int64_t a2 = mx / x + (mx % x == 0 ? 0 : 1);
  cout << min (a1, a2) << ' ' << max (a1, a1) << '\n';
 }
 return 0;
}
