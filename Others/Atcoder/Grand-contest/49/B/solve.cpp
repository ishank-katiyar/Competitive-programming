#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int n;
 cin >> n;
 string s;
 cin >> s;
 string t;
 cin >> t;
 int c1 = count (s.begin(), s.end(), '1');
 int c2 = count (t.begin(), t.end(), '1');
 if (((c1 % 2) != (c2 % 2)) || (c1 < c2)) {
  cout << -1 << '\n';
  return 0;
 }
 if (c1 == 0 && c2 == 0) {
  cout << 0 << '\n';
  return 0;
 }
 set <int> s1, s2;
 for (int i = 0; i < n; i++) {
  if (s[i] == '1') {
   s1.insert (i);
  }
  if (t[i] == '1') {
   s2.insert (i);
  }
 }
 long long int ans = 0;
 for (auto i: s2) {
  auto it = s1.lower_bound (i);
  if (it == s1.end()) {
   cout << -1 << '\n';
   return 0;
  }
  ans += (*it - i);
  s1.erase (it);
 }
 int sz = (int) s1.size();
 assert (sz % 2 == 0);
 vector <int> a (s1.begin(), s1.end());
 for (int i = 0; i < sz; i += 2) {
  int X = a[i];
  X++;
  ans += (a[i + 1] - X);
  ans++;
 }
 cout << ans << '\n';
 return 0;
}
