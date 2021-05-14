#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int n;
 cin >> n;
 vector<int> a(n);
 for (auto& i: a) cin >> i;
 vector<int> dp(n + 1, INT_MAX);
 dp[0] = INT_MIN;
 for (int i = 0; i < n; i++) {
  int j = upper_bound (dp.begin(), dp.end(), a[i]) - dp.begin();
  if (dp[j - 1] < a[i] && a[i] < dp[j]) dp[j] = a[i];
 }
 int ans = 0;
 for (int i = 1; i <= n; i++) {
  if (dp[i] < INT_MAX) ans = i;
 }
 cout << ans << '\n';
 return 0;
}
