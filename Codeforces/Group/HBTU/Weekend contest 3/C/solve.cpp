#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
 #include <bits/debugger.hpp>
 #define __int64 __int64_t
#else 
 #define debug(a...) //
#endif

const int maxa = 1e6 + 1;
vector<bool> is_prime(maxa , true);
set<__int64> s;

void seive() {
 for(int i = 2; i < maxa; i++) {
  if(is_prime[i]) {
   s.insert((__int64) i * i);
   for(int j = 2 * i; j < maxa; j += i) is_prime[j] =false;
  }
 }
}

int main()
{
 ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
 seive();
 int n;
 cin >> n;
 for(int i = 0; i < n; i++) {
  __int64 x;
  cin >> x;
  if(s.count(x)) cout << "YES";
  else cout << "NO";
  cout << '\n';
 }
 return 0;
}
