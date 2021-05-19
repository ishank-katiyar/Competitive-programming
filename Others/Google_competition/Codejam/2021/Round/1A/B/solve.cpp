#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int T;
 cin >> T;
 for (int tt = 1; tt <= T; tt++) {
  int m;
  cin >> m;
  vector<int64_t> a;
  while (m--) {
   int x, p;
   cin >> p >> x;
   while (x--) {
    a.push_back (p);
   }
  }
  int n = int (a.size());
  assert (n <= 10);
  int64_t ans = 0;
  for (int mask = 1; mask < (1 << n); mask += 1) {
   int64_t sum = 0, prod = 1;
   for (int i = 0; i < n; i++) {
    if ((mask >> i) & 1) {
     sum += a[i];
    } else {
     prod *= a[i];
    }
   }
   if (prod == sum) {
    ans = max (ans, prod);
   }
  }
  cout << "Case #" << tt << ": " << ans << '\n';
 }
 return 0;
}
