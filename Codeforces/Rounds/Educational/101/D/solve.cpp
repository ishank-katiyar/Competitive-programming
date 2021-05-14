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
  vector<pair<int, int>> ans;
  vector<int> a (n + 1);
  for (int i = 1; i <= n; i++) a[i] = i;
  
  auto ceil = [] (int A, int B) -> int {
   if (A % B == 0) return A / B;
   return A / B + 1;
  };

  auto oper = [&] (int x, int y) {
   a[x] = ceil (a[x], a[y]);
   ans.emplace_back (x, y);
  };
  
  for (int i = 3; i < n; i++) {
   if (i == 32) continue;
   oper (i, n);
  }
  if (n > 32) {
   while (a[n] != 1) {
    oper (n, 32);
   }
  }
  while (a[min (n, 32)] != 1) {
   oper (min(n, 32), 2);
  }
  assert (static_cast <int> (ans.size()) <= n + 5);
  for (int i = 3; i <= n; i++) assert (a[i] == 1);
  cout << static_cast <int> (ans.size()) << '\n';
  for (auto& i: ans) cout << i.first << ' ' << i.second << '\n';
 }
 return 0;
}
