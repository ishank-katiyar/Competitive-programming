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
  int n, X, p, k;
  cin >> n >> X >> p >> k;
  p--, k--;
  vector<int> a(n);
  for (auto& i: a) cin >> i;
  sort (a.begin(), a.end());
  if (a[p] == X) {
   cout << 0 << '\n';
   continue;
  }
  if (a[k] == X) {
   if (p > k) {
    for (int i = k; i < n; i++) {
     if (a[i] == X) a[i] = INT_MAX;
    }
   }
   else if (p < k) {
    for (int i = k; i >= 0; i--) {
     if(a[i] == X) a[i] = -1;
    }
   }
  }
  sort (a.begin(), a.end());
  assert (a[k] != X);
  int ans = -1;
  if (a[k] > X) {
   auto it = upper_bound(a.begin(), a.end(), X);
   int idx = it - a.begin();
   if (p >= idx && p <= k) {
    ans = p - idx + 1;
   }
  }
  else if (a[k] < X) {
   auto it = upper_bound(a.begin(), a.end(), X);
   int idx = it - a.begin();
   idx--;
   if (p <= idx && p >= k) {
    it = lower_bound(a.begin(), a.end(), X);
    idx = it - a.begin();
    idx--;
    assert (idx >= k);
    assert (p <= idx);
    ans = idx - p + 1;
   }
  }
  cout << ans << '\n';
 }
 return 0;
}
