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
  int n;
  cin >> n;
  set<pair<int, int>> s;
  while(n--) {
   int x, y;
   cin >> x >> y;
   s.insert(make_pair(x, y));
  }
  n = (int) s.size();
  int ans = 0;
  while(n >= 3) ans += n, n /= 2;
  cout << ans << '\n';
 }
}
