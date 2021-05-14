#include <bits/stdc++.h>
using namespace std;

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int t;
 cin >> t;
 while(t--) {
  int x1, y1, z1, x2, y2, z2;
  cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
  int ans = 0;
  int mn1 = min(z1,y2);
  ans += mn1 * 2;
  z1 -= mn1;
  y2 -= mn1;
  int m2 = min(y1, y2);
  y1 -= m2;
  y2 -= m2;
  int m3 = min(y1, x2);
  y1 -= m3;
  x2 -= m3;
  int m4 = min(z1, z2);
  z1 -= m4;
  z2 -= m4;
  int m5 = min(z2, x1);
  z2 -= m5;
  x1 -= m5;
  int m6 = min(y1, z2);
  ans -= m6 * 2;
  y1 -= m6;
  z2 -= m6;
  cout << ans << '\n';
 }
}
