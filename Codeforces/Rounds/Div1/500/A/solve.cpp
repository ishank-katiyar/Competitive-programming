#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int n;
 cin >> n;
 if (n == 1) {
  cout << 0 << '\n';
  return 0;
 }
 vector<long long int> a(2 * n);
 for (auto& i: a) cin >> i;
 sort (a.begin(), a.end());
 long long int ans = (a[n - 1] - a[0]) * (a[2 * n - 1] - a[n]);
 for (int i = n; i < 2 * n - 1; i++) {
  ans = min (ans, (a[i] - a[i - n + 1]) * (a[2 * n - 1] - a[0]));
 }
 cout << ans << '\n';
 return 0;
}
