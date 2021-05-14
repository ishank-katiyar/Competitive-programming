#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int n, m;
  cin >> n >> m;
  set <int> s;
  for (int i = 0; i < n + m; i++) {
   int x;
   cin >> x;
   s.insert (x);
  }
  cout << n + m - (int) s.size() << '\n';
 }
 return 0;
}
