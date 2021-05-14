#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int64_t n, m, x;
  cin >> n >> m >> x;
  int64_t yy = (x - 1) / n;
  int64_t xx = (x - 1) % n + 1;
  // cout << xx << ' ' << yy << '\n';
  cout << (xx - 1) * m + yy + 1 << '\n';
 }
 return 0;
}
