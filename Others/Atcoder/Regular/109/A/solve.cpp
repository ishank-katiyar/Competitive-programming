#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int a, b, x, y;
 cin >> a >> b >> x >> y;
 // int ans = x + min (x, y) * max (abs (a - b) - 1, 0);
 int ans = -1;
 if (a >= b) {
  int dif = abs (a - b);
  dif = max (dif - 1, 0);
  ans = x + min (y, 2 * x) * dif;
 }
 else {
  int dif = abs (a - b);
  ans = x + min (y, 2 * x) * dif;
 }
 cout << ans << '\n';
 return 0;
}
