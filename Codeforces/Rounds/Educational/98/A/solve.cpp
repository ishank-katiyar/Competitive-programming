#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int x, y;
  cin >> x >> y;
  cout << x + y + max (abs (x - y) - 1, 0) << '\n';
 }
 return 0;
}
