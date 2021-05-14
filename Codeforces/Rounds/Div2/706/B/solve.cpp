#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int n, k;
  cin >> n >> k;
  set <int> s;
  for (int i = 0; i < n; i++) {
   int x;
   cin >> x;
   s.insert (x);
  }

  auto mex = [] (set <int> S) -> int {
   int N = static_cast <int> (S.size());
   for (int i = 0; i <= N; i++) {
    if (S.count (i) == 0) {
     return i;
    }
   }
   return N;
  };

  if (k== 0) {
   cout << n << '\n';
   continue;
  }

  if (*(--s.end()) == n - 1) {
   cout << n + k << '\n';
  } else {
   cout << n + (s.count((*(--s.end()) + mex(s) + 1) / 2) == 0 ? 1 : 0) << '\n';
  }
 }
 return 0;
}
