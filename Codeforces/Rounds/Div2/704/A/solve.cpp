#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int64_t p, a, b, c;
  cin >> p >> a >> b >> c;
  if (p % a == 0 || p % b == 0 || p % c == 0) {
   cout << 0 << '\n';
   continue;
  }
  int64_t aa = (p / a) * a;
  int64_t bb = (p / b) * b;
  int64_t cc = (p / c) * c;
  cout << min ({aa + a - p, bb + b - p, cc + c - p}) << '\n';
 }
 return 0;
}
