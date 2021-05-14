#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int64_t n;
  cin >> n;
  while (n % 2 == 0) n /= 2;
  cout << (n == 1 ? "NO": "YES") << '\n';
 }
 return 0;
}
