#include <bits/stdc++.h>
using namespace std;

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int n, m, k;
 cin >> n >> m >> k;
 vector<pair<int, int>> a;
 bool ok = true;
 for (int i = 1; i <= n; i++) {
  if (ok) {
   for (int j = 1; j <= m; j++) {
    a.emplace_back(i, j);
   }
  } 
  else {
   for (int j = m; j >= 1; j--) {
    a.emplace_back(i, j);
   }
  }
  ok ^= 1;
 }
 while (k > 1) {
  cout << 2 << ' ';
  cout << a.back().first << ' ' << a.back().second << ' ';
  a.pop_back();
  cout << a.back().first << ' ' << a.back().second << '\n';
  a.pop_back();
  k--;
 }
 cout << (int) a.size() << ' '; 
 for (auto& i: a) cout << i.first << ' ' << i.second << ' ';
 cout << '\n';
 return 0;
}
