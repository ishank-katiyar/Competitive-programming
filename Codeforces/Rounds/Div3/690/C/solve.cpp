#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int x;
  cin >> x;
  if (x > 45) {
   cout << -1 << '\n';
   continue;
  }
  string ans = "";
  for (int i = 9; i >= 1; i--) {
   if (x >= i) {
    ans += to_string(i);
    x -= i;
   }
  }
  sort (ans.begin(), ans.end());
  if (x > 0) ans = "-1";
  cout << ans << '\n';
 }
 return 0;
}
