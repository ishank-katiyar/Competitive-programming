#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int test_case;
 cin >> test_case;
 for (int tt = 1; tt <= test_case; tt++) {
  cout << "Case #" << tt << ": ";
  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int> (n));
  for (auto& i: a) for (auto& j: i) cin >> j;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
   long long cur = 0;
   int ii = 0, jj = i;
   while (ii < n && jj < n) cur += a[ii][jj], ii++, jj++;
   ans = max (ans, cur);
  }
  for (int i = 1; i < n; i++) {
   long long cur = 0;
   int ii = i, jj = 0;
   while (ii < n && jj < n) cur += a[ii][jj], ii++, jj++;
   ans = max (ans, cur);
  }
  cout << ans << '\n';
 }
 return 0;
}
