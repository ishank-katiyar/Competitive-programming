#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int n;
 cin >> n;
 ll k;
 cin >> k;
 if (k == 1) {
  cout << n << '\n';
  return 0;
 }
 map<ll, int> mp;
 vector<ll> a(n);
 for (auto& i: a) cin >> i, mp[i]++;
 sort(a.begin(), a.end());
 map<int, int> index;
 for (int i = 0; i < n; i++) {
  index[a[i]] = i;
 }
 vector<int> dp(n);
 for (int i = 0; i < n; i++) {
  dp[i] = 1;
  if (a[i] % k == 0 && mp.count(a[i] / k) > 0) {
   dp[i] += dp[index[a[i] / k]];
  }
 }
 int ans = 0;
 for (int i = n - 1; i >= 0; i--) {
  if (mp.count(a[i] * k) == 0) {
   ans += (dp[i] + 1) / 2;
  }
 }
 cout << ans << '\n';
 return 0;
}
