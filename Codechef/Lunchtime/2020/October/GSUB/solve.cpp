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
  int q;
  cin >> q;
  vector<int> a (n);
  for (auto& i: a) cin >> i;
  int ans = 1;
  for (int i = 1; i < n; i++) {
   if (a[i] != a[i - 1]) {
    ans++;
   }
  }
  while (q--) {
   int x;
   cin >> x;
   x--;
   int value;
   cin >> value;
   if (value != a[x]) {
    if (x > 0 && value == a[x - 1]) ans--;
    if (x < n - 1 && value == a[x + 1]) ans--;
    if (x > 0 && a[x] == a[x - 1]) ans++;
    if (x < n - 1 && a[x] == a[x + 1]) ans++;
    a[x] = value;
   }
   cout << ans << '\n';
  }
 }
 return 0;
}
