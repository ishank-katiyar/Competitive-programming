#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int l, r;
  cin >> l >> r;
  if (r < 2 *l) cout << r << '\n';
  else cout << -1 << '\n';
 }
 return 0;
}
