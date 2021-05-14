#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;

  while (q--) {
   int l, r;
   cin >> l >> r;
   l--, r--;
   bool ok = false;
   for (int i = 0; i < l; i++) {
    if (s[i] == s[l]) ok = true;
   }
   for (int i = r + 1; i < n; i++) {
    if (s[i] == s[r]) ok = true;
   }
   cout << (ok ? "YES" : "NO") << '\n';
  }
 }
 return 0;
}
