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
  vector<vector<int>> a(m);
  for (int i = 0; i < n; i++) {
   int x;
   cin >> x;
   a[x % m].push_back (x);
  }
  int ans = static_cast <int> (a[0].size()) > 0;
  for (int i = 1; i <= (m) / 2; i++) {
   if (i == (m - i) % m) {
    if (static_cast <int> (a[i].size()) == 0) {
     continue;
    }
    ans += 1; 
    continue;
   }
   int x1 = static_cast <int> (a[i].size());
   int x2 = static_cast <int> (a[(m - i) % m].size());
   if (x1 == x2) {
    if (x1 > 0) {
     ans += 1;
    }
   }
   else {
    int mn = min (x1, x2);
    ans += 1;
    ans += x1 + x2 - mn - mn - 1;
   }
   // cout << i << ' ' << ans << '\n';
  }
  cout << ans << '\n';
 }
 return 0;
}
