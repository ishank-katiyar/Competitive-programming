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
  vector<pair<int64_t, int64_t>> m, d;
  for (int i = 0; i < 2 * n; i++) {
   int x, y;
   cin >> x >> y;
   if (x == 0) {
    m.push_back (make_pair(abs(y), y));
   }
   if (y == 0) {
    d.push_back (make_pair(abs(x), x));
   }
  }
  sort (m.begin(), m.end());
  sort (d.begin(), d.end());
  long double ans = 0;
  for (int i = 0; i < n; i++) {
   ans += sqrt(m[i].first * m[i].first + d[i].first * d[i].first);
  }
  cout << fixed << setprecision(15) << ans << '\n';
 }
 return 0;
}
