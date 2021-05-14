#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int a, b;
  while (cin >> a >> b) {
    int ans = 0;
    while (a <= b) {
      ans++;
      a *= 3;
      b *= 2;
    }
    cout << ans << '\n';
  }
  return 0;
}
