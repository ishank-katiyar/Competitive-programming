#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 map <int64_t, int> mp;
 for (int64_t i = 1; i <= static_cast <int> (1e4); i++) {
  mp[i * i * i]++;
 }
 int t;
 cin >> t;
 while (t--) {
  int64_t x;
  cin >> x;
  bool ok = false;
  for (int64_t i = 1; i <= static_cast <int> (1e4); i++) {
   ok |= mp.count (x - i * i * i);
  }
  cout << (ok ? "YES" : "NO") << '\n';
 }
 return 0;
}
