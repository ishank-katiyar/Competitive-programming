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
  vector<int64_t> k (n);
  for (int i = 0; i < n; i++) {
   cin >> k[i];
  }
  vector<int64_t> c (m);
  for (int i = 0; i < m; i++) {
   cin >> c[i];
  }
  sort (k.begin(), k.end());
  vector<int64_t> pre_sum (m + 1, 0);
  for (int i = 1; i <= m; i++) {
   pre_sum[i] += pre_sum[i - 1] + c[i - 1];
  }
  int64_t ans = LLONG_MAX;
  if (n <= m) ans = pre_sum[n];
  int64_t sum = 0;
  for (int i = 0; i < n; i++) {
   sum += c[k[i] - 1];
   if (n - 1 - i <= m) ans = min (ans, sum + pre_sum[n - 1 - i]);
  }
  assert (ans != LLONG_MAX);
  cout << ans << '\n';
 }
 return 0;
}
