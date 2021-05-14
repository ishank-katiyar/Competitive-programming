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

const int maxn = 1e8 + 1;
bitset<maxn> is_prime;
// vector<bool> is_prime(maxn , true);

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
 int c = 0;
 for(int i = 2; i < maxn; i++) {
  if(is_prime[i]) {
   c++;
   if(c % 100 == 1) cout << i << '\n';
  }
 }
 return 0;
}
