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
  int n, m;
  cin >> n >> m;
  bool ok = false;
  vector<vector<int>> a(n, vector<int> (4, 0));
  for (auto& i: a) cin >> i[0] >> i[1] >> i[2] >> i[3];
  int cnt = 0;
  for (int i = 0; i < n; i++) {
   if (a[i][1] == a[i][2]) cnt++;
  }
  ok = (cnt > 0);
  ok &= (m % 2 == 0);
  cout << (ok ? "YES" : "NO") << '\n';
 }
 return 0;
}
