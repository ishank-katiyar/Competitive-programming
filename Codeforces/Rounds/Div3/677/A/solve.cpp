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
  int x = (n % 10) - 1;
  int ans = 0;
  ans += x * 10;
  int d = 0;
  while (n > 0) ans += ++d, n /= 10;
  cout << ans << '\n';
 }
 return 0;
}
