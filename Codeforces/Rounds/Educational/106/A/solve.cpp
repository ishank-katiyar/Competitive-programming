#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int n, k1, k2;
  cin >> n >> k1 >> k2;
  int w, b;
  cin >> w >> b;

  auto f = [] (int W, int K1, int K2) -> bool {
   int mx = 0;
   if (K1 == 0 || K2 == 0) {
    mx = max (K1, K2) / 2;
   }
   for (int i = 1; i <= min (K1, K2); i++) {
    int cur = i;
    cur += (K1 - i) / 2;
    cur += (K2 - i) / 2;
    mx = max (mx, cur);
   }
   return W <= mx;
  };

  cout << (f (w, k1, k2) && f (b, n - k1, n - k2) ? "YES" : "NO") << '\n';
 }
 return 0;
}
