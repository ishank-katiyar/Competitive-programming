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

void seive() {
 is_prime.set();
 is_prime[1] = false;
 for(int i = 2; i < maxn; i++) {
  if(is_prime[i]) {
   for(int j = i * 2; j < maxn; j += i) is_prime[j] = false;
  }
 }
}

bool iszero(int n) {
 while(n) {
  if(n % 10 == 0) return true;
  n /= 10;
 }
 return false;
}

bool check(int n) {
 while(n) {
  string s = to_string(n);
  s.erase(s.begin());
  if(s.empty() == true) break;
  n = stoi(s);
  if(is_prime[n] == false) return false;
 }
 return true;
}

int main()
{
 ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
 seive();
 vector<int> dp(maxn , 0);
 for(int i = 2; i < maxn; i++) {
  if(is_prime[i] && (iszero(i) == false) && check(i) == true) dp[i] += dp[i - 1] + 1;
  else dp[i] += dp[i - 1];
 }
 int t;
 cin >> t;
 while(t--) {
  int n;
  cin >> n;
  cout << dp[n] << '\n';
 }
 return 0;
}
