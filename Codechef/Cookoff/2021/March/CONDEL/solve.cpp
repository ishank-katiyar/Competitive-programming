#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int n;
  cin >> n;
  int K;
  cin >> K;
  vector<int> a (n);
  for (int i = 0; i < n; i++) {
   cin >> a[i];
  }
  vector<int> dp (n);
  dp[0] = a[0];
  for (int i = 1; i < n; i++) {
   dp[i] += dp[i - 1] + a[i];
  }
  auto f = [&] (int L, int R) -> int {
   if (L == 0) {
    return dp[R];
   }
   return dp[R] - dp[L - 1];
  };
  int64_t ans = LLONG_MAX;
  for (int i = K - 1; i < n; i++) {
   int64_t x = f (i - K + 1, i);
   int64_t cur_ans = (x * (x + 1)) / 2;
   cur_ans += dp.back() - x;
   ans = min (ans, cur_ans);
  }
  cout << ans << '\n';
 }
 return 0;
}
