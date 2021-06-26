#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
 #include <bits/debugger.hpp>
 #define __int64 __int64_t
#else 
 #define debug(a...) //
#endif

bool pair_d(vector<int> &a) {
 int n = (int) a.size();
 for(int i = 0; i < n; i++) {
  for(int j = i + 1; j < n; j++) if(__gcd(a[i] , a[j]) != 1) return false;
 }
 return true;
}

int main()
{
 int n , k;
 cin >> n >> k;
 vector<int> a(n);
 for(int& i : a) cin >> i;
 for(int mask = 0; mask < (1 << n); mask++) {
  vector<int> cur;
  for(int i = 0; i < n; i++) {
   if((mask >> i) & 1) cur.emplace_back(a[i]);
  }
  if(pair_d(cur) == false) continue;
  int kk = k;
  for(int& i : cur) {
   int gd = __gcd(i , kk);
   kk /= gd;
  }
  if(kk == 1) {
   cout << "YES" << '\n';
   return 0;
  }
 }
 cout << "NO" << '\n';
 return 0;
}