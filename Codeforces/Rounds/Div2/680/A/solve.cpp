#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int n, x;
  cin >> n >> x;
  vector<int> a (n);
  for (auto& i: a) cin >> i;
  vector<int> b (n);
  for (auto& i: b) cin >> i;
  sort (a.begin(), a.end());
  sort (b.rbegin(), b.rend());
  bool ok = true;
  for (int i = 0; i < n; i++) {
   ok &= (a[i] + b[i] <= x);
  }
  cout << (ok ? "Yes" : "No") << '\n';
 }
 return 0;
}
