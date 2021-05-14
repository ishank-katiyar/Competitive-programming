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

const int maxn = 1e5 + 1;
bitset<maxn> is_prime;

void seive() {
 is_prime.set();
 for(int i = 2; i < maxn; i++) {
  if(is_prime[i]) {
   for(int j = 2 * i; j < maxn; j += i) is_prime[j] = false;
  }
 }
}

int main()
{
 ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
 seive();
 vector<__int64> prices;
 for(int i = 2; i < maxn; i++) {
  if(is_prime[i]) prices.emplace_back((__int64) i * i);
 }
 debug(prices.size());
 int t;
 cin >> t;
 while(t--) {
  __int64 n , k;
  cin >> n >> k;
  int ans = upper_bound(prices.begin() , prices.end() , k) - prices.begin();
  int ans1 = upper_bound(prices.begin() , prices.end() , n) - prices.begin();
  cout << ans1 << ' ' << max(ans1 - ans, 0) << '\n';
 }
 return 0;
}
