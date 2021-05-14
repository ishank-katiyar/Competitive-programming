#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 const int maxn = 1e6 + 1;
 vector<bool> dp (maxn, false);
 dp[2020] = true;
 dp[2021] = true;
 for (int i = 2022; i < maxn; i++) {
  if (dp[i - 2020]) dp[i] = true;
  if (dp[i - 2021]) dp[i] = true;
 }
 int t;
 cin >> t;
 while (t--) {
  int n;
  cin >> n;
  cout << (dp[n] ? "YES": "NO") << '\n';
 }
 return 0;
}
