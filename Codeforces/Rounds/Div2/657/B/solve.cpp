#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve (ll l, ll r, ll m) {
 for (ll i = l; i <= r; i++) {
  ll x = m + l - r;
  ll n;
  if (x % i == 0) n = x / i;
  else n = x / i + 1;
  if (n == 0) n++;
  if (n * i >= m + l - r && n * i <= m + r - l) {
   int a = i;
   int b, c;
   ll xx = n * i - m;
   if (xx < 0) b = r, c = b + xx;
   else c = r, b = c - xx;
   cout << a << ' ' << b << ' ' << c << '\n';
   return ;
  }
 } 
}

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int t;
 cin >> t;
 while (t--) {
  ll l, r, m;
  cin >> l >> r >> m;
  solve(l, r, m);
 }
 return 0;
}
