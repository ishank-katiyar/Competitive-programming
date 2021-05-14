#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  string a, b;
  cin >> a >> b;
  auto f = [] (string B, string sub) -> bool {
   int sz = static_cast <int> (B.size());
   int sz1 = static_cast <int> (sub.size());
   for (int i = 0; i <= sz - sz1; i++) {
    if (B.substr (i, sz1) == sub) {
     return true;
    }
   }
   return false;
  };
  int n = static_cast <int> (a.size());
  int m = static_cast <int> (b.size());
  int ans = n + m;
  for (int i = 0; i < n; i++) {
   string ss = "";
   for (int j = i; j < n; j++) {
    ss += a[j];
    if (f (b, ss) == true) {
     ans = min (ans, n + m - 2 * (j - i + 1));
    }
   }
  }
  cout << ans << '\n';
 }
 return 0;
}
