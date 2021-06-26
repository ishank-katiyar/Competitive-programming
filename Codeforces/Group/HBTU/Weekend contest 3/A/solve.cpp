#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
 #include <bits/debugger.hpp>
#else 
 #define debug(a...) //
 #define __int64 __int64_t
#endif

const int maxn = 1e4 + 1;
vector<int> prime;

bool is_prime(int n) {
 for(int i = 2; i <= sqrt(n); i++) if(n % i == 0) return false;
 return true; 
}

int main()
{
 ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
 for(int i = 2; i < maxn; i++) if(is_prime(i)) prime.emplace_back(i);
 int sz = (int) prime.size();
 int n , k;
 cin >> n >> k;
 int cnt = 0;
 for(int i = 1; i < sz; i++) {
  if(prime[i] + prime[i - 1] + 1 <= n && is_prime(prime[i] + prime[i - 1] + 1)) cnt++;
  if(prime[i] + prime[i - 1] + 1 > n) break;
 }
 cout << (k > cnt ? "NO" : "YES") << '\n';
 return 0;
}
