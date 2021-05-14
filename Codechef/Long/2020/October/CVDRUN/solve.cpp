#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int t;
 cin >> t;
 while (t--) {
  int n, x, y, k;
  cin >> n >> k >> x >> y;
  if (k == 0) {
   cout << (x == y ? "YES" : "NO") << '\n';
   continue;
  }
  //if (n % k == 0) cout << (((x - y + n) % n) % k == 0 ? "YES" : "NO") << '\n';
  //else cout << "YES" << '\n';
  map<int, int> mp;
  while (mp.count(x) == 0) mp[x] = 1, x += k, x %= n;
  cout << (mp.count(y) ? "YES" : "NO") << '\n';
 }
 return 0;
}
