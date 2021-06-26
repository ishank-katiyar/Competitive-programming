#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
 #include <bits/debugger.hpp>
 #define __int64 __int64_t
#else 
 #define debug(a...) //
#endif

const int maxn = 1e4 + 1;
vector<int> sf(maxn , -1);
vector<bool> is_prime(maxn , true);
map<int , set<int>> kk;

void seive() {
 for(int i = 2; i < maxn; i++) {
  if(is_prime[i]) {
   for(int j = i; j < maxn; j += i) {
    sf[j] = i;
    if(j != i) is_prime[j] = false;
   }
  }
 }
}

int main()
{
 ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
 seive();
 int n , k;
 cin >> n >> k;
 for(int i = 0; i < n; i++) {
  int x;
  cin >> x;
  while(sf[x] != -1) {
   int y = sf[x];
   int cnt = 0;
   while(x % y == 0) cnt++ , x /= y;
   kk[y].insert(cnt);
  }
 }
 bool ok = true;
 while(sf[k] != -1) {
  int x = sf[k];
  int cnt = 0;
  while(k % x == 0) cnt++ , k /= x;
  auto it = kk[x].lower_bound(cnt);
  ok &= (it != kk[x].end());
 }
 cout << (ok ? "YES" : "NO") << '\n';
 return 0;
}
