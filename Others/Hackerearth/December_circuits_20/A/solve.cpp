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
  map <int, vector<int>> mp;
  for (int i = 0; i < n; i++) {
   int x;
   cin >> x;
   mp[x].push_back (i);
  }
  int64_t ans = 0;
  for (auto& i: mp) {
   ans += i.second.back() - i.second.front();
  }
  cout << ans << '\n';
 }
 return 0;
}
