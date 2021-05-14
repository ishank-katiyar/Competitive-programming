#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int64_t n, k;
  cin >> n >> k;
  int64_t mm = n / k + (n % k ? 1 : 0);
  k *= mm;
  cout << (k / n + (k % n == 0 ? 0 : 1)) << '\n';
 }
 return 0;
}
