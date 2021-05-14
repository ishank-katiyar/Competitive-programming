#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 cout.tie(0);
 int n, k, l;
 cin >> n >> k >> l;
 int m = n * k;
 vector<long long> a(m);
 for (auto& i: a) cin >> i;
 sort (a.begin(), a.end());
 if (a[n - 1] - a[0] > l) {
  cout << 0 << '\n';
  return 0;
 }
 int idx = 0;
 for (int i = 0; i < m; i++) {
  if (a[i] - a[0] <= l) idx = i;
 }
 int cnt = k;
 vector<bool> used(m);
 long long ans = 0;
 int c = 0;
 for (int i = 0; i < m; i++) {
  if (a[i] - a[0] > l) {
   break;
  }
  if (cnt == k) {
   ans += a[i];
   cnt = 1;
   used[i] = true;
   c++;
   if (c == n) {
    break;
   }
  }
  else cnt++;
 }
 assert (idx >= n - 1);
 n = n - c;
 while (1) {
  if (n <= 0) {
   break;
  }
  if (used[idx] == true) {
   idx--;
   continue;
  }
  ans += a[idx];
  idx--;
  n--;
 }
 cout << ans << '\n';
 return 0;
}
