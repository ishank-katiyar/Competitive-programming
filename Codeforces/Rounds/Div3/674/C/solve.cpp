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
  int n;
  cin >> n;
  int x = sqrt(n);
  int ans1 = x - 1;
  if (n % x == 0) ans1 += (n / x) - 1;
  else ans1 += (n / x);
  int ans2 = x;
  if (n % (x + 1) == 0) ans2 += (n / (x + 1)) - 1;
  else ans2 += (n / (x + 1));
  cout << min (ans1, ans2) << '\n';
 }
 return 0;
}
