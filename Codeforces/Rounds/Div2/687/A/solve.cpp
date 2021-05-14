#include <bits/stdc++.h>

using namespace std;

#define ll long long 
long long max (ll a, ll b, ll c, ll d) {
 return max ({a, b, c, d});
}

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  long long n, m, r, c;
  cin >> n >> m >> r >> c;
  // // long long ans = ((n * (n - 1)) / 2) * m;
  // // ans += ((m * (m - 1)) / 2) * n;
  // cout << ans << '\n';
  long long ans = max (abs(r - 1) + abs (c - 1), abs (r - 1) + abs(c - m), abs (r - n) + abs (c - 1), abs(r - n) + abs (c - m));
  cout << ans << '\n';
 }
 return 0;
}
