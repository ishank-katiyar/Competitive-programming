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
  int prev;
  cin >> prev;
  int ans = 0;
  for (int i = 1; i < n; i++) {
   int x;
   cin >> x;
   int mn = min (prev, x);
   int mx = max (x, prev);
   while (mn * 2 < mx) {
    mn *= 2;
    ans += 1;
   }
   prev = x;
  }
  cout << ans << '\n';
 }
 return 0;
}
