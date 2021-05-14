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
  vector<int> a (n);
  for (int i = 0; i < n; i++) {
   cin >> a[i];
  }
  vector<int64_t> dp (n);
  dp[n - 1] = a[n - 1];
  for (int i = n - 2; i >= 0; i--) {
   if (i + a[i] < n) dp[i] += dp[i + a[i]] + a[i];
   else dp[i] = a[i];
  }
  cout << *max_element (dp.begin(), dp.end()) << '\n';
 }
 return 0;
}
