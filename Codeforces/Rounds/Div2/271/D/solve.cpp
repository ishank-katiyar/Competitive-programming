#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);

 const int MOD = static_cast <int> (1e9 + 7);
 const int maxn = static_cast <int> (1e5 + 1);

 int t, k;
 cin >> t >> k;

 vector<int> dp (maxn);

 dp[1] = 1;
 if (k == 1) {
  dp[1] += 1;
 }

 for (int i = 2; i < maxn; i++) {
  (dp[i] += dp[i - 1]) %= MOD;
  if (i == k) {
   (dp[i] += 1) %= MOD;
  }
  if (i > k) {
   (dp[i] += dp[i - k]) %= MOD;
  }
 }

 for (int i = 2; i < maxn; i++) {
  (dp[i] += dp[i - 1]) %= MOD;
 }

 while (t--) {
  int a, b;
  cin >> a >> b;
  cout << (dp[b] - dp[a - 1] + MOD) % MOD << '\n';
 }
 return 0;
}
