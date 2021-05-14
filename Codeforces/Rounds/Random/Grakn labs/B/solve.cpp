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
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto& i: a) cin >> i;
  set<int> s(a.begin(), a.end());
  int x = (int) s.size();
  if (k == 1 && x != 1) {
   cout << -1 << '\n';
   continue;
  }
  if (k == 1 && x == 1) {
   cout << 1 << '\n';
   continue;
  }
  k--;
  x--;
  int ans;
  if (x % k) ans = x / k + 1;
  else ans = x / k;
  ans = max (ans, 1);
  cout << ans << '\n';
 }
 return 0;
}
