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
  map <int, pair<int, int>> mp;
  for (int i = 1; i <= n; i++) {
   int x;
   cin >> x;
   mp[x].first++;
   mp[x].second = i;
  }
  int ans = -1;
  for (auto& i: mp) {
   if (i.second.first == 1) {
    ans = i.second.second;
    break;
   }
  }
  cout << ans << '\n';
 }
 return 0;
}
