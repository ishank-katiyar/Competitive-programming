#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 cout.tie(0);
 int n;
 cin >> n;
 vector<int> ans(n);
 vector<pair<int, int>> a(n);
 map<int, int> mp;
 map<int, int> c;
 set<int> s;
 for (auto& i: a) cin >> i.first >> i.second, mp[i.first] = i.second, c[i.first]++, c[i.second]++, s.insert (i.first);
 for (auto& i: c) {
  if (i.second == 1 && s.count(i.first)) {
   ans[0] = i.first; 
   break;
  }
 }
 int idx = -1;
 int x = 0;
 while (1) {
  x = mp[x];
  idx += 2;
  if (x == 0 || idx >= n) {
   break;
  }
  assert (idx < n);
  ans[idx] = x;
 }
 idx = 0;
 x = ans[0];
 while (1) {
  x = mp[x];
  idx += 2;
  if (x == 0 || idx >= n) {
   break;
  }
  ans[idx] = x;
 }
 for (auto& i: ans) cout << i << ' ';
 cout << '\n';
 return 0;
}
