#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 const int MOD = static_cast <int> (1e8);
 int n1, n2, k1, k2;
 cin >> n1 >> n2 >> k1 >> k2;

 vector<vector<vector<int>>> dp (n1 + 1, vector<vector<int>> (n2 + 1, vector<int> (3, -1)));

 function<int(int, int, int, int, int)> f = [&] (int N1, int N2, int K1, int K2, int type) -> int {

  if (dp[N1][N2][type] != -1) {
   return dp[N1][N2][type];
  }

  int ret = 0;

  if (type == 1) {
   if (N1 <= K1 && N2 == 0) {
    dp[N1][N2][type] = 1;
    return 1;
   }
   for (int i = 1; i <= min (N1, K1); i++) {
    (ret += f (N1 - i, N2, K1, K2, 3 - type)) %= MOD;
   }
  } else {
   if (N2 <= K2 && N1 == 0) {
    dp[N1][N2][type] = 1;
    return 1;
   }
   for (int i = 1; i <= min (N2, K2); i++) {
    (ret += f (N1, N2 - i, K1, K2, 3 - type)) %= MOD;
   }
  }

  dp[N1][N2][type] = ret;
  return ret;
 };

 cout << (f (n1, n2, k1, k2, 1) + f (n1, n2, k1, k2, 2)) % MOD << '\n';

 return 0;
}
