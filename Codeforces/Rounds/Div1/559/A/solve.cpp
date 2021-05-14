#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 cout.tie(0);
 int n;
 cin >> n;
 int m;
 cin >> m;
 long long sum = 0;
 vector<long long> a(n);
 for (auto& i: a) cin >> i, sum += i;
 sort (a.begin(), a.end());
 vector<long long> b(m);
 for (auto& i: b) cin >> i;
 sort (b.begin(), b.end());
 if (b[0] < a[n - 1]) {
  cout << -1 << '\n';
  return 0;
 }
 long long ans = sum * m;
 for (int i = 0; i < m; i++) {
  if (i == 0) {
   if (b[i] == a.back()) continue;
   else {
    ans += b[i] - a[n - 2];
   }
  }
  else ans += b[i] - a[n - 1];
 }
 cout << ans << '\n';
 return 0;
}
