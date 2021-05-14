#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int64_t n, m, a, b;
  cin >> n >> m >> a >> b;
  vector<int64_t> s (m);
  for (int i = 0; i < m; i++) {
   cin >> s[i];
  }
  sort (s.begin(), s.end());
  int64_t mn = [&] () -> int64_t {
   if (a < b) return a - 1;
   return n - a;
  }();
  int64_t mx = abs (a - b) - 1 + mn;
  mn++;
  // cout << mx << ' ' << mn << '\n';
  int ans = 0;
  for (int i = m - 1; i >= 0 && mx >= mn; i--) {
   if (s[i] <= mx) ans++, mx--;
  }
  cout << ans << '\n';
 }
 return 0;
}
