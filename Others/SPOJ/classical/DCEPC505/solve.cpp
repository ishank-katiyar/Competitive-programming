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
   for(int j = 2 * i; j < maxn; j += i) is_prime[j] = false , c[j] += p(j , i);
  }
 }
}


int main()
{
 ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
 seive();
 vector<int> ans;
 for(int i = 6; i < maxn; i++) {
  if((int) ans.size() == (int) 2e6) break;
  if(c[i] == 2) ans.emplace_back(i);
 }
 debug(ans.size() , ans.back());
 int t;
 cin >> t;
 while(t--) {
  int n;
  cin >> n;
  cout << ans [n - 1] << '\n';
 }
 return 0;
}
