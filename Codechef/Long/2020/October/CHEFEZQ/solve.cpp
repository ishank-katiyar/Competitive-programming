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
  int k;
  cin >> k;
  vector<long long int> a(n);
  for (auto& i: a) cin >> i;
  long long int ans = 0;
  long long int sum = 0;
  for (int i = 0; i < n; i++) {
   sum += a[i];
   if (sum < k) {
    ans = i + 1;
    break;
   }
   sum -= k;
  }
  if (ans == 0) {
   ans = n + sum / k + 1;
  }
  assert (ans > 0);
  cout << ans << '\n';
 }
 return 0;
}
