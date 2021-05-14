#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 vector<string> s(2);
 cin >> s[0] >> s[1];
 int n = (int) s[0].size();
 vector<int> dp(n + 1);
 for (int i = 2; i <= n; i++) {
  int cnt = 0;
  cnt += (s[0][i - 1] == '0');
  cnt += (s[0][i - 2] == '0');
  cnt += (s[1][i - 1] == '0');
  cnt += (s[1][i - 2] == '0');
  if (cnt >= 3) cnt = 1;
  else cnt = 0;
  dp[i] = max(dp[i - 1], dp[i - 2] + cnt);
  if (i > 2) {
   cnt = 0;
   cnt += (s[0][i - 1] == '0');
   cnt += (s[0][i - 2] == '0');
   cnt += (s[0][i - 3] == '0');
   cnt += (s[1][i - 1] == '0');
   cnt += (s[1][i - 2] == '0');
   cnt += (s[1][i - 3] == '0');
   if (cnt == 6) {
    dp[i] = max(dp[i], max(dp[i - 1], dp[i - 3] + 2));
   }
  }
 }
 cout << dp[n] << '\n';
 return 0;
}
