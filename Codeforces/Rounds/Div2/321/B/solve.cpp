#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int n, d;
 cin >> n >> d;
 vector<pair<ll, ll>> a(n);
 for(auto& i: a) cin >> i.first >> i.second;
 sort(a.begin(), a.end());
 vector<ll> dp(n);
 dp[0] = a[0].second;
 for(int i = 1; i < n; i++) dp[i] += dp[i-1] + a[i].second;
 ll ans = 0;
 for(int i = 0; i < n; i++) {
  int j = lower_bound(a.begin(), a.end(), make_pair(a[i].first - d, LLONG_MAX)) - a.begin();
  if(j > 0) ans = max(ans, dp[i] - dp[j-1]);
  if(j == 0) ans = max(ans, dp[i]);
 }
 cout << ans << '\n';
 return 0;
}
