#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int64_t a, x, y;
  cin >> a >> y >> x;
  if (a >= y) {
   cout << x * y << '\n';
  } else {
   cout << x * a + 1 << '\n';
  }
 }
 return 0;
}
