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
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& i: a) cin >> i;
  vector<int> b(n);
  for (auto& i: b) cin >> i;
  vector<int> c(n);
  for (auto& i: c) cin >> i;
  vector<int> ans(n);
  ans[0] = a[0];
  for (int i = 1; i < n - 1; i++) {
   if (a[i] == ans[i - 1] && b[i] != ans[i - 1]) ans[i] = b[i];
   else if(a[i] == ans[i - 1] && b[i] == ans[i - 1]) ans[i] = c[i];
   else ans[i] = a[i];
  }
  if (b[n - 1] != ans[n - 2] && b[n - 1] != a[0]) ans[n - 1] = b[n - 1];
  if (a[n - 1] != ans[n - 2] && a[n - 1] != a[0]) ans[n - 1] = a[n - 1];
  if (c[n - 1] != ans[n - 2] && c[n - 1] != a[0]) ans[n - 1] = c[n - 1];
  for (auto& i: ans) cout << i << ' ';
  cout << '\n';
 }
 return 0;
}
