#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 cout.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int n;
  cin >> n;
  int k;
  cin >> k;
  vector<int> a(n);
  for (auto& i: a) cin >> i;
  sort (a.rbegin(), a.rend());
  if (k == 0) {
   cout << a[n - 1] - a[0] << '\n';
   continue;
  }
  k++;
  long long ans = 0;
  for (int i = 0; i < n && k; i++) {
   ans += a[i];
   k--;
  }
  cout << ans << '\n';
 }
 return 0;
}
