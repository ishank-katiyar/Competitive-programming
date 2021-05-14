#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int64_t n, q, k;
 cin >> n >> q >> k;
 vector<int64_t> a (n);
 for (int i = 0; i < n; i++) {
  cin >> a[i];
 }

 if (n == 1) {
  while (q--) {
   int l, r;
   cin >> l >> r;
   assert (l == 1 && r == 1);
   cout << k - 1 << '\n';
  }
  return 0;
 }
 
 assert (n > 1);

 vector<int64_t> dp (n);

 // if (a[1] > 2) dp[0] = 1;
 // dp[0] += a[0];

 for (int i = 1; i < n - 1; i++) {
  // if (a[i + 1] - a[i - 1] > 2) dp[i] += dp[i - 1] + 1;
  // else dp[i] += dp[i - 1];
  dp[i] += dp[i - 1] + (a[i + 1] - a[i - 1] - 1);
 }

 // if (a[n - 2] < k - 1) dp[n - 1] += dp[n - 2] + 1;
 // else dp[n - 1] += dp[n - 2];
 // dp[n - 1] += dp[n - 2] + (k - a[n - 1] + 1);

 while (q--) {
  int l, r;
  cin >> l >> r;
  l--, r--;

  if (l == r) {
   cout << k - 1 << '\n';
   continue;
  }

  int64_t ans = 0;
  // if (l == 0) ans = dp[r];
  // else ans = dp[r] - dp[l - 1];

  ans += (a[l + 1] - 1);

  ans += (k - a[r - 1]);

  l++, r--;

  if (l <= r) {
   ans += dp[r] - dp[l - 1];
  }

  cout << ans - 2 - (r - l + 1) << '\n';
 }
 return 0;
}
