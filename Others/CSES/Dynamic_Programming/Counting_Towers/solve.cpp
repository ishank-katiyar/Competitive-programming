#include <bits/stdc++.h>

using namespace std;

int64_t bpow(int64_t a , int64_t b, int mod) {
 int64_t res(1);
 while(b) {
  if(b % 2 == 1) (res *= a) %= mod;
  (a *= a) %= mod;
  b /= 2;
 }
 return res;
}

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 const int maxn = static_cast <int> (1e6 + 1);
 const int mod = static_cast <int> (1e9 + 7);
 vector<int64_t> dp (maxn);
 dp[1] = 2;
 dp[2] = 8;
 // int64_t one = 1, two = 1;
 // int64_t pw1 = 0, pw2 = 0;
 for (int i = 3; i < maxn; i++) {
  // int64_t cur_one = (two * bpow ((int64_t) 2, pw2, mod)) % mod;
  // int64_t cur_two = (one * bpow ((int64_t) 2, pw1, mod)) % mod;
  // (cur_one += bpow ((int64_t) 2,(int64_t) 2 * (i - 1), mod)) %= mod;
  // (cur_two += bpow ((int64_t) 2,(int64_t) i - 1, mod)) %= mod;
  // dp[i] = (cur_one + cur_two) % mod;
  // pw2 += 2;
  // pw1 += 1;
  // (cur_two *= bpow (bpow ((int64_t) 2, pw2, mod),(int64_t) mod - 2, mod)) %= mod;
  // (cur_one *= bpow (bpow ((int64_t) 2, pw1, mod),(int64_t) mod - 2, mod)) %= mod;
  // (one += cur_one) %= mod;
  // (two += cur_two) %= mod;
  (dp[i] = 6 * dp[i - 1] - 7 * dp[i - 2]) %= mod;
  dp[i] += mod;
  dp[i] %= mod;
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
