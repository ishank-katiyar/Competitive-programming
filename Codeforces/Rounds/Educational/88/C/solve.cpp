#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--)  {
  int64_t h, c, T;
  cin >> h >> c >> T;
  if (h == T) {
   cout << 1 << '\n';
   continue;
  } else if (h + c >= 2 * T) {
   cout << 2 << '\n';
   continue;
  }
  int64_t K = (h - T) / (2 * T - h - c);
  int64_t ans1 = K * (h + c) + h;
  int64_t ans2 = (K + 1) * (h + c) + h;
  if (abs ((2 * K + 3) * (ans1 - (2 * K + 1) * T)) <= abs ((2 * K + 1) * (ans2 - (2 * K + 3) * T))) {
   cout << 2 * K + 1 << '\n';
  } else {
   cout << 2 * K + 3 << '\n';
  }
 }
 return 0;
}
