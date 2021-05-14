#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int64_t n, c01, c10;
  cin >> n >> c01 >> c10;
  int64_t even = 0, odd = 0;
  for (int i = 0; i < n; i++) {
   int x;
   cin >> x;
   if (x == 1) (i % 2 == 0 ? odd : even) += 1;
  }
  cout << min ((((n + 1) / 2) - odd) * c01 + (even) * c10, odd * c10 + (n / 2 - even) * c01) << '\n';
 }
 return 0;
}
