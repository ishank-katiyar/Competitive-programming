#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int n, c0, c1, h;
  cin >> n >> c0 >> c1 >> h;
  string s;
  cin >> s;
  int ans = INT_MAX;
  int cc0 = count (s.begin(), s.end(), '0');
  // int cc1 = n - cc0;
  for (int i = 0; i <= n; i++) {
   int e0 = i;
   int e1 = n - i;
   ans = min (ans, e0 * c0 + e1 * c1 + abs(e0-cc0) * h);
  }
  cout << ans << '\n';
 }
 return 0;
}
