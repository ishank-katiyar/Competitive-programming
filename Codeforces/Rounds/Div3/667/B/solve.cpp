#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int t;
 cin >> t;
 while(t--) {
  ll a, b, x, y, n;
  cin >> a >> b >> x >> y >> n;
  if(a < b) swap(a, b), swap(x, y);
  ll aa = a, bb = b, xx = x, yy = y, nn = n;
  ll dd = b - y;
  if(dd > n) dd = n;
  b -= dd;
  n -= dd;
  dd = a - x;
  if(dd > n) dd = n;
  a -= dd;
  n -= dd;
  dd = aa - xx;
  if(dd > nn) dd = nn;
  aa -= dd;
  nn -= dd;
  dd = bb - yy;
  if(dd > nn) dd = nn;
  bb -= dd;
  nn -= dd;
  cout << min(a * b, aa * bb) << '\n';
 }
 return 0;
}
