#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int n, m, a, b;
 cin >> n >> m >> a >> b;
 int ans = n * a;
 if(n % m == 0) ans = min(ans, (n / m) * b);
 else ans = min(ans, (n/m+1) * b);
 for(int i = m; i <= n; i += m) {
  ans = min(ans, (i / m) * b + (n - i) * a);
 } 
 cout << ans << '\n';
}
