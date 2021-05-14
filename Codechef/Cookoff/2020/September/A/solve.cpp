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
  int n, k, l;
  cin >> n >> k >> l;
  if (n == 1) {
    cout << 1 << '\n';
    continue;
  }
  if (k * l < n || k == 1) {
   cout << -1 << '\n';
   continue;
  }
  int ans = 1;
  while (n--) {
   cout << ans << ' ';
   ans++;
   if (ans == k + 1) ans = 1;
  }
  cout  << '\n';
 }
 return 0;
}
