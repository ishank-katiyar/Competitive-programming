#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int64_t x, r, m;
  cin >> x >> r >> m;
  r *= 60;
  m *= 60;
  if (r <= x) {
   cout << (r <= m ? "YES" : "NO") << '\n';
   continue;
  }
  r -= x;
  m -= x;
  r *= 2;
  cout << (r <= m ? "YES" : "NO") << '\n';
 }
 return 0;
}
