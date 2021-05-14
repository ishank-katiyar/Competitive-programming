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

const int maxn = 1e7 + 1;
bitset<maxn> is_prime;
vector<__int64> ans(maxn , 1);

__int64 p(int j , int i) {
 __int64 ret = 0;
 while(j % i == 0) j /= i , ret++;
 return ret;
}

void seive()
{
 is_prime.set();
 is_prime[1] = false;
 for(int i = 2; i < maxn; i++) {
  if(is_prime[i]) {
   for(int j = i; j < maxn; j += i) {
    if(j != i) is_prime[j] = false;
    ans[j] *= (p(j , i) + 1);
   }
  }
 }
}

int main()
{
 ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
 seive();
 for(int i = 1; i < 10; i++) debug(i , ans[i]);
 vector<__int64> dp(maxn);
 for(int i = 1; i < maxn; i++) {
  dp[i] += dp[i - 1] + (i * ans[i]);
 }
 int n;
 cin >> n;
 cout << dp[n] << '\n';
 return 0;
}
