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
  vector<int> a (n);
  for (int i = 0; i < n; i++) {
   cin >> a[i];
  }
  vector<int> ans (n);
  for (int mask = 0; mask < (1 << n); mask++) {
   if (__builtin_popcount(mask) <= 1) continue;
   vector<pair<int, int>> aa;
   for (int i = 0; i < n; i++) {
    if ((mask >> i) & 1) {
     aa.emplace_back (a[i], i);
    }
   }
   int sz = (int) aa.size();
   assert (sz > 1);
   sort (aa.rbegin(), aa.rend());
   for (int i = 0; i < min (3, sz); i++) {
    ans[aa[i].second]++;
   }
  }
  for (int i = 0; i < n; i++) {
   cout << ans[i] << ' ';
  }
  cout << '\n';
 }
 return 0;
}
