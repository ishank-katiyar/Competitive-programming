#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int n, m;
  cin >> n >> m;
  int gd = 0;
  for (int i = 0; i < m; i++) {
   int x;
   cin >> x;
   gd = __gcd (gd, x);
  }
  int64_t ans = INT_MAX;
  for (int64_t i = 1; i * i <= gd; i++) {
   if (gd % i) continue;
   if (i <= n) ans = min (ans, n - i);
   if (gd / i <= n) ans = min (ans, n - (gd / i));
  }
  cout << ans << '\n';
 }
 return 0;
}
