#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int n, x;
  cin >> n >> x;
  bool ok = false;
  for (int i = 1; i * i <= x; i++) {
   if (x % i) continue;
   ok |= (i <= n && x / i <= n);
  }
  cout << (ok ? "Yes" : "No") << '\n';
 }
 return 0;
}
