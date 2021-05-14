#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int n;
  cin >> n;
  map<string , multiset<int>> mp;
  for (int i = 1; i <= n; i++) {
   string s;
   cin >> s;
   int x;
   cin >> x;
   mp[s].insert (x);
  }
  int ans = 0;
  for (auto& i: mp) {
   ans += max (i.second.count (0), i.second.count (1));
  }
  cout << ans << '\n';
 }
 return 0;
}
