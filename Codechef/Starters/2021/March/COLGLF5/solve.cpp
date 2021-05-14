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
  vector<pair<int, int>> a;
  for (int i = 0; i < n; i++) {
   int x;
   cin >> x;
   a.push_back (make_pair (x, 1));
  }
  for (int i = 0; i < m; i++) {
   int x;
   cin >> x;
   a.push_back (make_pair (x, 2));
  }
  sort (a.begin(), a.end());
  int ans = 0;
  if (a.front().second == 2) {
   ans += 1;
  }
  for (int i = 1; i < n + m; i++) {
   ans += (a[i].second != a[i - 1].second);
  }
  cout << ans << '\n';
 }
 return 0;
}
