#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int n;
  cin >> n;
  map <int, int> mp;
  for (int i = 0; i < n; i++) {
   int x;
   cin >> x;
   mp[x]++;
  }
  vector <int> a;
  for (auto& i: mp) {
   a.push_back (i.second);
  }
  sort (a.begin(), a.end());
  int sz = static_cast <int> (a.size());
  int suf = n;
  int ans = INT_MAX;
  int pre = 0;
  for (int i = 0; i < sz; i++) {
   ans = min (ans, suf - (a[i] * (sz - i)) + pre);
   pre += a[i];
   suf -= a[i];
  }
  cout << ans << '\n';
 }
 return 0;
}
