#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 1;
vector<int> is(maxn, true);

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 is[0] = is[1] = false;
 for (int i = 2; i < maxn; i++) {
  if (is[i]) {
   for (int j = 2 * i; j < maxn; j += i) {
    is[j] = false;
   }
  }
 }
 vector<int> dp (maxn, 0);
 for (int i = 2; i < maxn; i++) {
  if (is[i] && is[i - 2]) {
   dp[i] += dp[i - 1] + 1;
  } else dp[i] = dp[i - 1];
 }
 int t;
 cin >> t;
 while (t--) {
  int n;
  cin >> n;
  cout << dp[n] << '\n';
 }
 return 0;
}
