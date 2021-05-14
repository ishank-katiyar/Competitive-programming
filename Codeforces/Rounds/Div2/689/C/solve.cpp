#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int n, m;
  cin >> n >> m;
  vector<int> a (n);
  for (int i = 0; i < n; i++) {
   cin >> a[i];
  }
  int len = n;
  while (a.empty() == false && a.back() == (int) a.size()) a.pop_back();
  len = (int) a.size();
  double ans = 1.0;
  for (int i = 0; i < m; i++) {
   int LEN;
   cin >> LEN;
   double p;
   cin >> p;
   if (LEN >= len) {
    ans *= ((double)1.0 - p);
   }
  }
  if (len == 0) {
   cout << 1 << '\n';
   continue;
  }
  ans = (double) 1.0 - ans;
  cout << fixed << setprecision (10) << ans << '\n';
 }
 return 0;
}
