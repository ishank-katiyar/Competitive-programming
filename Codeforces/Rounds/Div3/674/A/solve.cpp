#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int t;
 cin >> t;
 while (t--) {
  int n, x;
  cin >> n >> x;
  if (n <= 2) {
   cout << 1 << '\n';
   continue;
  }
  bool ok = (n - 2) % x;
  cout << (n - 2) / x + 1 + ok << '\n';
 }
 return 0;
}
