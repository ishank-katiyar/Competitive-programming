#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
const int maxn = 1e7 + 1;
vector<long long int> dp(maxn);

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 dp[0] = 1;
 dp[1] = 0;
 for(int i = 2; i < maxn; i++) {
  dp[i] = dp[i-1] * 2 + dp[i-2] * 3;
  dp[i] %= mod;
 }
 int n;
 cin >> n;
 cout << dp[n] << '\n';
 return 0;
}
