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
  long long int n;
  cin >> n;
  long long int sum = 0;
  long long int x = 0;
  long long int ans = 0;
  while (n > 0) {
   x  = 2 * x + 1;
   sum = (x * (x + 1)) / 2;
   if (sum > n) break;
   n -= sum;
   ans++;
  }
  cout << ans << '\n';
 }
 return 0;
}
