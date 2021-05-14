#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int64_t n, u, v;
  cin >> n >> u >> v;
  set<int64_t> a;
  vector<int> A (n);
  for (int i = 0; i < n; i++) {
   int64_t x;
   cin >> x;
   A[i] = x;
   a.insert (x);
  }
  bool ok = false;
  for (int i = 1; i < n; i++) {
   ok |= (abs(A[i] - A[i - 1]) > 1);
  }
  if (ok == true) {
   cout << 0 << '\n';
   continue;
  }
  if (static_cast <int> (a.size()) == 1) {
   cout << min (u + v, 2 * v) << '\n';
  } else {
   cout << min (u, v) << '\n';
  }
 }
 return 0;
}
