#include <bits/stdc++.h>

using namespace std;

void solve() {
 int n, k;
 cin >> n >> k;
 vector<int> x(n);
 vector<int> y(n);
 for(auto& i: x) cin >> i;
 for(auto& i: y) cin >> i;
 sort(x.begin(), x.end());
 vector<int> dp1(n);
 for(int i = 0; i < n; i++) {
  int j = lower_bound(x.begin(), x.end(), x[i] - k) - x.begin();
  dp1[i] = i - j + 1;
  if(i > 0) dp1[i] = max(dp1[i], dp1[i-1]);
 }
 vector<int> dp(n);
 for(int i = 0; i < n; i++) {
  int j = lower_bound(x.begin(), x.end(), x[i] - k) - x.begin();
  dp[i] = i - j + 1;
  if(j > 0) dp[i] += dp1[j-1];
  if(i > 0) dp[i] = max(dp[i], dp[i-1]);
 }
 cout << dp[n-1] << '\n';
}

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int t;
 cin >> t;
 while(t--) solve();
 return 0;
}
