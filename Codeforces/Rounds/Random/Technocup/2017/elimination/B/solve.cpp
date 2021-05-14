#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 cout.tie(0);
 string a, b;
 cin >> a >> b;
 set<pair<char, char>> ans;
 int n = (int) a.size();
 for (int i = 0; i < n; i++) {
  if (a[i] != b[i]) {
   if (a[i] > b[i]) ans.insert (make_pair(b[i], a[i]));
   else ans.insert (make_pair(a[i], b[i]));
  }
 }
 set<char> s;
 for (auto& i: ans) {
  if (s.count (i.first) || s.count (i.second)) {
   cout << -1 << '\n';
   return 0;
  }
 }
 for (int i = 0; i < n; i++) {
  for (auto& j: ans) {
   if (b[i] == j.first) b[i] = j.second;
   else if (b[i] == j.second) b[i] = j.first;
  }
 }
 if (a != b) {
  cout << -1 << '\n';
  return 0;
 }
 cout << (int) ans.size() << '\n';
 for (auto& i: ans) {
  cout << i.first << ' ' << i.second << '\n';
 }
 return 0;
}
