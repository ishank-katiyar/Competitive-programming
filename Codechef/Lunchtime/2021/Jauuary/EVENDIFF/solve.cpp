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
  int odd = 0;
  for (int i = 0; i < n; i++) {
   int x;
   cin >> x;
   odd += (x % 2 == 1);
  }
  cout << min (odd, n - odd) << '\n';
 }
 return 0;
}
