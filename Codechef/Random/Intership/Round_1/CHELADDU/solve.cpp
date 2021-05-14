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
  int k;
  cin >> k;
  k--;
  vector<int> a (n);
  for (auto& i: a) cin >> i;
  sort (a.begin(), a.end());
  int ans = INT_MAX;
  for (int i = k; i < n; i++) {
   ans = min (ans, a[i] - a[i - k]);
  }
  cout << ans << '\n';
 }
 return 0;
}
