#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int n, m;
 cin >> n >> m;
 vector<long long> a (n), b (m);
 long long gd = 0;
 for (int i = 0; i < n; i++) {
  cin >> a[i];
  if (i >= 1) {
   if (i == 1) {
    gd = abs (a[i] - a[i - 1]);
   }
   else gd = __gcd (gd, (long long)abs (a[i] - a[i - 1]));
  }
 }
 // cout << "gd: " << gd << '\n';
 for (int i = 0; i < m; i++) {
  cin >> b[i];
  cout << __gcd (gd, b[i] + a[0]) << ' ';
 }
 cout << '\n';
 return 0;
}