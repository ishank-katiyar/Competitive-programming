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
  vector<pair<int64_t, int64_t>> a (n);
  for (int i = 0; i < n; i++) {
   cin >> a[i].first;
   a[i].second = 1;
  }
  for (int i = 0; i < n; i++) {
   if (a[i].first % x) break;
   a.emplace_back (a[i].first / x, x * a[i].second);
   n = static_cast <int> (a.size());
  }
  int64_t sum = 0;
  for (auto& i: a) sum += (i.first * i.second);
  cout << sum << '\n';
 }
 return 0;
}
