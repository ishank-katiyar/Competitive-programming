#include <bits/stdc++.h>
using namespace std;

const int maxn = 501;

vector<vector<int>> dp(maxn, vector<int> (maxn, 1e9));

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 for(int i = 1; i < maxn; i++) {
  dp[i][i] = 0;
 }
 for(int i = 1; i < maxn; i++) {
  for(int j = 1; j < maxn; j++) {
   if(i == j) continue;
   int ans = 1e9;
   for(int k = 1; k < i; k++) {
    ans = min(ans, dp[k][j] + dp[i - k][j] + 1);
   }
   for(int k = 1; k < j; k++) {
    ans = min(ans, dp[i][k] + dp[i][j - k] + 1);
   }
   dp[i][j] = ans;
  }
 }
 int a, b;
 cin >> a >> b;
 cout << dp[a][b] << '\n';
 return 0;
}
