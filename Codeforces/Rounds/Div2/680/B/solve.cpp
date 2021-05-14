#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  cout << max (a + b, c + d) << '\n';
 }
 return 0;
}
