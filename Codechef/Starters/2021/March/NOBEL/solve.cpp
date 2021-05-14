#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int n, m;
  cin >> n >> m;
  map <int, int> mp;
  for (int i = 0; i < n; i++) {
   int x;
   cin >> x;
   mp[x]++;
  } 
  bool ok = false;
  for (int i = 1; i <= m; i++) {
   ok |= (mp.count(i) == 0);
  }
  cout << (ok ? "Yes" : "No") << '\n';
 }
 return 0;
}
