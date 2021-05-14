#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int n;
 cin >> n;
 vector<int> a (n);
 for (int i = 0; i < n; i++) {
  cin >> a[i];
 }
 int ans = 0;
 int mx = 0;
 for (int x = 2; x <= 1000; x++) {
  int cur = 0;
  for (auto& i: a) {
   if (i % x == 0) {
    cur++;
   }
  }
  if (cur > mx) {
   // cout << x << ' ' << cur << '\n';
   ans = x;
   mx = cur;
  }
 }
 cout << ans << '\n';
 return 0;
}
