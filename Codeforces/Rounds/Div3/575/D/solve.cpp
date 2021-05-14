#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 string S = "RGB";
 int tt = 10;
 while (tt--) S += S;
 int t;
 cin >> t;
 while (t--) {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  auto f = [&] (string ss) -> int {
   int ret = 1e9;
   for (int i = 0; i < 3; i++) {
    string a = S.substr(i, k);
    int cur = 0;
    for (int j = 0; j < k; j++) cur += (a[j] != ss[j]);
    ret = min(ret, cur);
   }
   return ret;
  };
  int ans = 1e9;
  for (int i = 0; i <= n - k; i++) {
   ans = min(ans, f(s.substr(i, k)));
  }
  cout << ans << '\n';
 }
 return 0;
}
