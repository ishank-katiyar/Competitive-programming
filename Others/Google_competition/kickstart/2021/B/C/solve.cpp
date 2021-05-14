#include <bits/stdc++.h>

using namespace std;

int main() 
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int TT;
  cin >> TT;
  for (int ttt = 1; ttt <= TT; ttt++) {
    cout << "Case #" << ttt << ": ";
    int64_t Z;
    cin >> Z;
    int64_t xx = sqrt (Z);
    auto f = [] (int64_t X) -> bool {
      if (X <= 1) {
        return false;
      }
      if (X == 2 || X == 3) {
        return true;
      }
      for (int64_t i = 2; i * i <= X; i++) {
        if (X % i == 0) {
          return false;
        }
      }
      return true;
    };
    vector<int64_t> aa;
    for (int64_t i = xx - 400; i <= xx + 200; i++) {
      if (f (i)) {
        aa.push_back (i);
      }
    }
    assert ((int)aa.size() > 2);
    int64_t ans = 0;
    int sz = aa.size();
    // cout << aa[0] << '\n';
    for (int i = 1; i < sz; i++) {
      // cout << aa[i] << ' ';
      if (aa[i] * aa[i - 1] <= Z) {
        ans = max (ans, aa[i] * aa[i - 1]);
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
