#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int n;
  cin >> n;
  assert (n <= 18);
  vector<int> a (n);
  for (int i = 0; i < n; i++) {
   cin >> a[i];
  }
  int ans = n;
  for (int mask = 0; mask < (1 << n); mask++) {
   vector<int> aa;
   for (int i = 0; i < n; i++) {
    if ((mask >> i) & 1) {
     // do nothing
    } else {
     aa.push_back (a[i]);
    }
   }
   bool ok = true;
   int cur_len = 1;
   int sz = static_cast <int> (aa.size());
   for (int i = 1; i < sz; i++) {
    if (aa[i] == aa[i - 1]) cur_len++;
    else {
     ok &= (cur_len % 2 == 0);
     cur_len = 1;
    }
   }
   if (sz > 0) {
    ok &= (cur_len % 2 == 0);
   }
   if (ok == true) ans = min (ans, __builtin_popcount (mask));
  }
  cout << ans << '\n';
 }
 return 0;
}
