#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int64_t n, k;
  cin >> n >> k;
  bool ok = true;
  for (int i = 0; i < n; i++) {
   int64_t x;
   cin >> x;
   bool cur_ok = x % k == 0;
   while (x <= static_cast <int64_t> (1e18)) {
    x += x;
    cur_ok |= (x % k == 0);
   }
   ok &= cur_ok;
  }
  while (k % 2 == 0) k /= 2;
  cout << (k == 1 || ok ? "YES" : "NO") << '\n';
 }
 return 0;
}
