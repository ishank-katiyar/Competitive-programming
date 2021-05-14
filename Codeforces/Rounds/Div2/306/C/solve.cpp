#include <bits/stdc++.h>
using namespace std;

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 string s;
 cin >> s;
 int n = (int) s.size();
 vector<vector<string>> dp(n, vector<string> (9, ""));
 string ans = "";
 for(int i = 0; i < n; i++) {
  int ss = s[i] - '0';
  ss %= 8;
  if(ss == 0) ss = 8;
  dp[i][ss] = s[i];
  if(ss == 8) ans = s[i];
  for(int j = 0; j < i; j++) {
   for(int k = 1; k <= 8; k++) {
    if((int) dp[j][k].size() > 0) {
     int ss1 = k * 2 + ss;
     ss1 %= 8;
     if(ss1 == 0) ss1 = 8;
     dp[i][ss1] = dp[j][k] + s[i];
     if(ss1 == 8) ans = dp[i][ss1];
    }
   }
  }
 }
 if(ans.empty() == false && count(ans.begin(), ans.end(), '0') == (int) ans.size()) ans = '0';
 if(ans == "") cout << "NO\n";
 else {
  cout << "YES\n" << ans << '\n';
 }
 return 0;
}
