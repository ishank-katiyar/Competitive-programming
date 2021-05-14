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
  vector<string> a(n);
  for (auto& i: a) cin >> i;
  vector<pair<int, int>> ans;
  if (a[0][1] == a[1][0]) {
   if (a[n - 2][n - 1] == a[0][1]) ans.emplace_back(n - 1, n);
   if (a[n - 1][n - 2] == a[0][1]) ans.emplace_back(n, n - 1);
  }
  else if (a[n - 1][n - 2] == a[n - 2][n - 1]) {
   if (a[n - 2][n - 1] == a[0][1]) ans.emplace_back(1, 2);
   if (a[n - 1][n - 2] == a[1][0]) ans.emplace_back(2, 1);
  }
  else {
   if (a[0][1] == '1') {
    assert (a[1][0] == '0');
    ans.emplace_back(1, 2);
   }
   if (a[1][0] == '1') {
    assert (a[0][1] == '0');
    ans.emplace_back(2, 1);
   }
   if (a[n - 1][n - 2] == '0') {
    assert (a[n - 2][n - 1] == '1');
    ans.emplace_back(n, n - 1);
   }
   if (a[n - 2][n - 1] == '0') {
    assert (a[n - 1][n - 2] == '1');
    ans.emplace_back(n - 1, n);
   }
  }
  assert ((int) ans.size() <= 2);
  cout << (int) ans.size() << '\n';
  for (auto& i: ans) cout << i.first << ' ' << i.second << '\n';
 }
 return 0;
}
