#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int n, k;
  cin >> n >> k;
  vector<long long> a (n * k);
  for (auto& i: a) cin >> i;
  sort (a.begin(), a.end());
  // int  K = k;
  long long ans = 0;
  int jump = n - ((n - 1) / 2);
  for (int i = ((n-1)/2) * k; i < n * k; i += jump) {
   ans += a[i];
  }
  // long long ans1 = 0;
  // for (int i = (n - 1) / 2; i < n * k; i += n) {
  //  ans1 += a[i];
  // }
  // ans = max (ans, ans1);
  cout << ans << '\n';
 }
 return 0;
}
