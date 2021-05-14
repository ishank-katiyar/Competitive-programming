#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 const int maxn = 1111;
 vector<int> dp (maxn);
 dp[0] = 1;
 for (int i = 1; i < maxn; i++) {
  int len = 2 * i + 1;
  int total = 2 * len + 2 * len - 4;
  assert (total % 2 == 0);
  if (2 * i - 1 >= maxn) continue;
  dp [2 * i - 1] = total / 2;
  dp [2 * i] = total / 2;
 }
 int n;
 cin >> n;
 int ans = 0;
 int sub = 0;
 if (n % 2 == 1) sub = 2;
 else sub = 4;
 while (n >= 0) {
  ans += dp[n];
  n -= sub;
 }
 cout << ans << '\n';
 return 0;
}