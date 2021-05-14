#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int w, h;
    cin >> w >> h;
    int ans = 1;
    while (w % 2 == 0)
      ans *= 2, w /= 2;
    while (h % 2 == 0)
      ans *= 2, h /= 2;
    int n;
    cin >> n;
    cout << (ans >= n ? "YES" : "NO") << '\n';
  }
  return 0;
}
