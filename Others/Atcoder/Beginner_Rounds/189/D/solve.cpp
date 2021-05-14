#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int n;
 cin >> n;
 vector<string> a (n);
 for (int i = 0; i < n; i++) {
  cin >> a[i];
 }
 vector<pair<int64_t, int64_t>> dp (n + 1);
 dp[0] = make_pair(1, 1);
 for (int i = 1; i <= n; i++) {
  if (a[i - 1] == "AND") {
   dp[i].first = 1 * dp[i - 1].first;
   dp[i].second = dp[i - 1].second * 1 + dp[i - 1].first * 1 + dp[i - 1].second * 1;
  } else {
   dp[i].first = dp[i - 1].first * 1 + dp[i - 1].first * 1 + dp[i - 1].second * 1;
   dp[i].second = dp[i - 1].second * 1;
  }
 }
 cout << dp[n].first << '\n';
 return 0;
}
