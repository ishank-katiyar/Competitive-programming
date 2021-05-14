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
  int ans = -1;
  if (n == 1) {
   ans = 0;
  }
  else if (n == 2) {
   ans = 1;
  }
  else {
   if (n % 2 == 1) {
    ans = min (3, n - 1);
   }
   else {
    ans = min (2, n - 1);
   }
  }
  cout << ans << '\n';
 }
 return 0;
}
