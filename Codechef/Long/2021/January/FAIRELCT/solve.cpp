#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int n, m;
  cin >> n >> m;
  multiset<int64_t> a, b;
  int64_t sum1 = 0, sum2 = 0;
  for (int i = 0; i < n; i++) {
   int64_t x;
   cin >> x;
   a.insert (x);
   sum1 += x;
  }
  for (int i = 0; i < m; i++) {
   int64_t x;
   cin >> x;
   b.insert (x);
   sum2 += x;
  }
  int64_t ans = 0;
  while (sum1 <= sum2 && b.empty() == false && a.empty() == false) {
   if (*(--b.end()) > *a.begin()) {
    sum1 -= *a.begin();
    sum2 += *a.begin();
    sum1 += *(--b.end());
    sum2 -= *(--b.end());
    b.erase (--b.end());
    a.erase (a.begin());
    ans++;
   }
   else break;
  }
  if (sum1 <= sum2) ans = -1;
  cout << ans << '\n';
 }
 return 0;
}
