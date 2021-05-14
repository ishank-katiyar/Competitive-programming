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

const int maxs = 1.5e8 + 1;
bitset<maxs> ans;
const int maxn = 1e7 + 1;
bitset<maxn> is_prime;
const int maxbit = 32;

void seive() {
 is_prime.set();
 is_prime[0] = is_prime[1] = false;
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
   bitset<maxbit> ss(i);
   string s = ss.to_string();
   reverse(s.begin() , s.end());
   while(s.back() == '0') s.pop_back();
   reverse(s.begin() , s.end());
   for(char ch : s) {
    
   }
  }
 } 
 return 0;
}
