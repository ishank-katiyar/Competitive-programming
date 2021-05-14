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
 vector<ll> pwr;
 ll x = 2;
 while (x < (ll) 1e9) pwr.push_back(x), x *= 2;
 pwr.push_back(x);
 map<ll, int> mp;
 vector<ll> a(n);
 for (auto& i: a) cin >> i, mp[i]++;
 ll ans = 0;
 for (int i = 0; i < n; i++) {
  for (auto& j: pwr) {
   if (j - a[i] != a[i]) ans += mp[j - a[i]];
   else ans += mp[j - a[i]] - 1;
  }
 }
 cout << ans / 2 << '\n';
 return 0;
}
