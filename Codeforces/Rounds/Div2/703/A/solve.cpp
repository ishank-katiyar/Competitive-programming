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
  vector<int64_t> a (n);
  int64_t sum = 0;
  for (int i = 0; i < n; i++) {
   cin >> a[i];
   sum += a[i];
  }
  bool ok = sum >= ((n * (n - 1)) / 2);
  for (int i = 0; i < n - 1; i++) {
   if (a[i] >= i) {
    a[i + 1] += a[i] - i;
   } else {
    ok = false;
   }
  }
  ok &= (a.back() >= n - 1);
  cout << (ok ? "YES" : "NO") << '\n';
 }
 return 0;
}
