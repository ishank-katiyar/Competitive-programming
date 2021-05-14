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
  long long int x, y, k;
  cin >> x >> y >> k;
  long long int tt = k * y + k;
  tt--;
  x--;
  long long int ans;
  if (tt % x) ans = tt / x + 1;
  else ans = tt / x;
  cout << ans + k << '\n';
 }
 return 0;
}


//1
//x  = 1 * x-1 + 1
//x - 1 + x
//2x - 2 + x = 3x - 3 + 1
