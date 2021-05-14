#ifdef LOCAL
 #include <P.hpp>
 #include <debugger.hpp>
 #define __int64 __int64_t
#else 
 #include <bits/stdc++.h>
 #define debug(a...) //
 // #define __int64 long long int
#endif
using namespace std;

const int maxn = 1e6 + 1;
bitset<maxn> is_prime;
vector<int> c(maxn , 0);

int p(int j , int i) {
 int ret = 0;
 while(j % i == 0) ret++ , j /= i;
 return ret;
}

void seive() {
 is_prime.set();
 for(int i = 2; i < maxn; i++) {
  if(is_prime[i]) {
   c[i]++;
   for(int j = 2 * i; j < maxn; j += i) is_prime[j] = false , c[j]++;
  }
 }
}

int main()
{
 ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
 seive();
 vector<vector<int>> dp(maxn , vector<int> (11 , 0));
 for(int i = 1; i < maxn; i++) {
  for(int j = 0; j <= 10; j++) {
   if(c[i] == j) dp[i][j] += dp[i - 1][j] + 1;
   else dp[i][j] += dp[i - 1][j];
  }
 }
 int t;
 cin >> t;
 while(t--) {
  int a , b , n;
  cin >> a >> b >> n;
  cout << dp[b][n] - dp[a - 1][n] << '\n';
 }
 return 0;
}
