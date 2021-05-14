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
  // vector<pair<pair<int, int>, int>> a (n);
  map <int, int64_t> mp;
  for (int i = 0; i < n; i++) {
   // cin >> a[i].first.first >> a[i].first.second >> a[i].second;
   int x, y, z;
   cin >> x >> y >> z;
   mp[y] += z;
  }
  int64_t ans = 0;
  int64_t sum = 0;
  for (auto& i: mp) {
   sum += i.second;
   ans = max (ans, sum / i.first + (sum % i.first != 0));
  }
  cout << ans << '\n';
 }
 return 0;
}
