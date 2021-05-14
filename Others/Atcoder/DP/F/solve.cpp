#include <bits/stdc++.h>
using namespace std;

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 string a, b;
 cin >> a >> b;
 int n = (int) a.size();
 int m = (int) b.size();
 vector<vector<int>> dp(n+1, vector<int> (m+1));
 for(int i = 1; i <= n; i++) {
  for(int j = 1; j <= m; j++) {
   if(a[i-1] == b[j-1]) dp[i][j] = max(dp[i-1][j-1] + 1, max(dp[i-1][j], dp[i][j-1]));
   else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
  }
 }
 //cout << dp[n][m] << '\n';
 int i = n, j = m;
 string ans = "";
 while(i > 0 && j > 0) {
  if(a[i-1] == b[j-1]) {
   ans += a[i-1];
   i--, j--;
  }
  else {
   if(dp[i-1][j] > dp[i][j-1]) i--;
   else j--;
  }
 }
 reverse(ans.begin(), ans.end());
 cout << ans << '\n';
 return 0;
}
