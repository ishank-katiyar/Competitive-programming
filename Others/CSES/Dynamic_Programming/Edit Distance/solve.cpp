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
 vector<vector<int>> dp(n+1, vector<int> (m+1, 1e9));
 dp[0][0] = 0;
 for(int i = 0; i <= n; i++) {
  for(int j = 0; j <= m; j++) {
   if (i) {
	    dp[i][j] = min(dp[i][j], dp[i-1][j] + 1);
   }
   if (j) {
	   dp[i][j] = min(dp[i][j], dp[i][j-1] + 1);
   }
   if (i && j) {
	   dp[i][j] = min(dp[i][j], dp[i-1][j-1] + (a[i-1] != b[j-1]));
   }
  }
 }
 cout << dp[n][m] << '\n';
 return 0;
}
