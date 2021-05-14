#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int n, r;
 cin >> n >> r;
 vector<int> a(n);
 for (auto& i: a) cin >> i;
 vector<int> dp(n, 1e9);
 for (int i = 0; i < n; i++) {
  if (a[i] == 0) continue;
  if (i - r >= 0 && dp[i - r] == 1e9) {
   cout << -1 << '\n';
   return 0;
  }
  int x = 0;
  if (i - r >= 0) x = dp[i - r];
  for (int j = max(i - r + 1, 0); j <= min(n - 1, i + r - 1); j++) {
   dp[j] = min(dp[j], x + 1);
  }
 }
 if (dp[n - 1] == 1e9) dp[n - 1] = -1;
 cout << dp[n - 1] << '\n';
 return 0;
}
