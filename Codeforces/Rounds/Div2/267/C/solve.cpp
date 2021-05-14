#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int64_t n, m, k;
 cin >> n >> m >> k;
 vector<int64_t> a (n + 1);
 for (int i = 1; i <= n; i++) {
  cin >> a[i];
 }
 vector<int64_t> pre(n + 1);
 for (int i = 1; i <= n; i++) {
  pre[i] += pre[i - 1] + a[i];
 }

 auto f = [&] (int l, int r) -> int64_t {
  return pre[r] - pre[l - 1];
 };

 vector<vector<int64_t>> dp (n + 1, vector<int64_t> (k + 1));
 for (int i = 1; i <= n; i++) {
  for (int j = 1; j <= k; j++) {
   if (i - m + 1 > 0) {
    dp[i][j] = max (dp[i][j], f(i - m + 1, i) + dp[i - m][j - 1]);
    dp[i][j] = max (dp[i][j], dp[i - 1][j]);
   }
  }
 }
 int64_t ans = 0;
 for (int i = 1; i <= n; i++) {
  ans = max (ans, dp[i][k]);
 }
 cout << ans << '\n';
 return 0;
}
