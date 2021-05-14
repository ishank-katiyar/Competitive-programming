#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int n, k;
 cin >> n >> k;
 long long ans = 0;
 if (k < 0) k *= -1;
 
 auto f = [&] (int X) -> long long int {
  if (X <= n) return X - 1;
  return 2 * n - X + 1;
 };

 for (int i = 2; i + k <= 2 * n; i++) {
  ans += f (i) * f (i + k);
 }
 cout << ans << '\n';
 return 0;
}
