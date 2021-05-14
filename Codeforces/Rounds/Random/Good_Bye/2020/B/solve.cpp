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
  map <int, int> mp;
  vector<int> a (n);
  for (int i = 0; i < n; i++) {
   int x;
   cin >> x;
   a[i] = x;
   mp[x]++;
  }
  int ans = 0;
  for (auto& i: mp) {
   if (i.second == 1) {
    ans++;
   } else {
    assert (i.second > 1);
    mp[i.first + 1]++;
    ans++;
   }
  }
  cout << ans << '\n';
 }
 return 0;
}
