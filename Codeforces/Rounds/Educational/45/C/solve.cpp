#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 cout.tie(0);
 int n;
 cin >> n;
 vector<string> a(n);
 for (auto& i: a) cin >> i;
 map<int, int> mp;
 for (int i = 0; i < n; i++) {
  int bal = 0, mn = 0;
  int sz = (int) a[i].size();
  for (int j = 0; j < sz; j++) {
   if (a[i][j] == '(') bal++;
   else bal--;
   mn = min (mn, bal);
  }
  if (mn < 0) {
   if (mn == bal) {
    mp[mn]++;
   }
  }
  else mp[bal]++;
 }
 long long ans = 0;
 for (int i = 0; i < n; i++) {
  int bal = 0, mn = 0;
  int sz = (int) a[i].size();
  for (int j = 0; j < sz; j++) {
   if (a[i][j] == '(') bal++;
   else bal--;
   mn = min (mn, bal);
  }
  //if (mn < 0 && mn == bal) ans += mp[-mn];
  if (mn >= 0 && bal > 0) ans += mp[-bal];
 }
 ans += 1LL * mp[0] * mp[0];
 cout << ans << '\n';
 return 0;
}
