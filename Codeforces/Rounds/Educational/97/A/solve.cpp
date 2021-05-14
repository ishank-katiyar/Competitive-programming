#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  long long int l, r;
  cin >> l >> r;
  if (2 * l > r) cout << "YES" << '\n';
  else cout << "NO" << '\n';
 }
 return 0;
}
