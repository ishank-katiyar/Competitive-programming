#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int n, p;
  cin >> n >> p;
  int edges = 2 * n + p;
  int u = 1, v = 2;
  while (edges--) {
   cout << u << ' ' << v << '\n';
   if (v == n) u++, v = u + 1;
   else v++;
  }
 }
 return 0;
}
