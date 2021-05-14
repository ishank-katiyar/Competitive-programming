#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int n, e, h, a, b, c;
  cin >> n >> e >> h >> a >> b >> c;

  int ans = INT_MAX;
  
  auto f = [&] (int cnt1, int cnt2, int cnt3) {
   assert (cnt1 + cnt2 + cnt3 == n);
   // cout << cnt1 << ' ' << cnt2 << ' ' << cnt3 << '\n';
   int tE = cnt1 * 2 + cnt3;
   int tH = cnt2 * 3 + cnt3;
   if (tE > e || tH > h) {
    return;
   }
   ans = min (ans, cnt1 * a + cnt2 * b + cnt3 * c);
  };

  function<void(int, int, int, int)> f1 = [&] (int index, int cnt1, int cnt2, int cnt3) {
   if (index == n) {
    f (cnt1, cnt2, cnt3);
    return;
   }
   f1 (index + 1, cnt1 + 1, cnt2, cnt3);
   f1 (index + 1, cnt1, cnt2 + 1, cnt3);
   f1 (index + 1, cnt1, cnt2, cnt3 + 1);
  };

  f1 (0, 0, 0, 0);

  if (ans == INT_MAX) {
   ans = -1;
  }

  cout << ans << '\n';
 }
 return 0;
}
