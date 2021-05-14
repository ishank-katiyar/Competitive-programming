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
  vector<int> a;
  int cnt = 0;
  for (int i = 0; i < n * m; i++) {
   int x;
   cin >> x;
   if (x < 0) {
    x = -x;
    cnt++;
   }
   a.push_back (x);
  }
  sort (a.begin(), a.end());
  int ans = accumulate (a.begin(), a.end(), 0);
  if (cnt % 2 == 1) {
   ans -= 2 * a[0];
  }
  cout << ans << '\n';
 }
 return 0;
}
