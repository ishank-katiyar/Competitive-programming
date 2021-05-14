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
// vector<bool> is_prime(maxn , true);

void seive(){
 is_prime.set();
 for(int i = 2; i < maxn ; i++) {
  if(is_prime[i]) {
   for(int j = 2 * i; j < maxn; j += i) is_prime[j] = false;
  }
 }
}

int main()
{
 ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
 seive();
 vector<int> dp(maxn , 0);
 for(int i = 1; i <= 4000; i++) {
  for(int j = 1; j <= 100; j++) {
   if(((i * i) + (j * j * j * j)) < maxn) {
    dp[((i * i) + (j * j * j * j))] = is_prime[((i * i) + (j * j * j * j))];
   }
  }
 }
 for(int i = 1; i < maxn; i++) dp[i] += dp[i - 1];
 int t;
 cin >> t;
 while(t--) {
  int n;
  cin >> n;
  cout << dp[n] << '\n';
 }
 return 0;
}
