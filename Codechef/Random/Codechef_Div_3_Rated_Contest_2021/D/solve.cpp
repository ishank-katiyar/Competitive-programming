#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int n, m;
  cin >> n >> m;
  vector<string> a (n);
  for (int i = 0; i < n; i++) {
   cin >> a[i];
  }
  int x = -1, y = -1, x1 = -1, y1 = -1;
  for (int i = 0; i < n; i++) {
   for (int j = 0; j < m; j++) {
    if (a[i][j] == '1'){
     if (x == -1) {
      assert (y == -1);
      x = i, y = j;
     }
     x1 = i, y1 = j;
    }
   }
  }
  bool ok = true;
  for (int i = x; i <= x1; i++) {
   for (int j = y; j <= y1; j++) {
    if (a[i][j] == '0') {
     ok = false;
    } else {
     a[i][j] = '0';
    }
   }
  }
  if (ok == false) {
   cout << "NO" << '\n';
   continue;
  }
  for (int i = 0; i < n; i++) {
   for (int j = 0; j < m; j++) {
    ok &= (a[i][j] == '0');
   }
  }
  cout << (ok ? "YES" : "NO") << '\n';
 }
 return 0;
}
