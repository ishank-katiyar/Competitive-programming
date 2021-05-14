#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int x, y;
  cin >> x >> y;
  string s;
  cin >> s;
  bool ok = true;
  if (x > 0) {
   ok &= count(s.begin(), s.end(), 'R') >= x;
  }
  if (x < 0) {
   x *= -1;
   ok &= count(s.begin(), s.end(), 'L') >= x;
  }
  if (y > 0) {
   ok &= count(s.begin(), s.end(), 'U') >= y;
  }
  if (y < 0) {
   y *= -1;
   ok &= count(s.begin(), s.end(), 'D') >= y;
 }
  cout << (ok ? "YES" : "NO") << '\n';
 }
 return 0;
}
