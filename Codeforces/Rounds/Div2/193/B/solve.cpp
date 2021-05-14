#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int n, k;
 cin >> n >> k;
 vector<long long int> a(n);
 for (auto& i: a) cin >> i;
 vector<long long int> dp(n);
 dp[0] = a[0];
 for (int i = 1; i < n; i++) {
  dp[i] += dp[i - 1] + a[i];
 }
 vector<long long int> dp1(n);
 dp1[k - 1] = dp[k - 1];
 for (int i = k; i < n; i++) {
  dp1[i] = max(dp1[i - 1], dp[i] - dp[i - k]);
 }
 vector<long long int> dp2(n);
 dp2[2 * k - 1] = dp[2 * k - 1];
 for (int i = 2 * k; i < n; i++) {
  dp2[i] = max(dp2[i - 1], dp[i] - dp[i - k] + dp1[i - k]);
 }
 long long int ans = dp2[n - 1];
 int x = -1, y = -1;
 for (int i = 0; i < n; i++) {
  if (dp2[i] == ans) {
   y = i - k + 1;
   ans -= (dp[i] - dp[i - k]);
   break;
  }
 }
 for (int i = 0; i < n; i++) {
  if (dp1[i] == ans) {
   x = i - k + 1;
   break;
  }
 }
 assert (x != -1 && y != -1);
 cout << x + 1 << ' ' << y + 1 << '\n';
 return 0;
}
