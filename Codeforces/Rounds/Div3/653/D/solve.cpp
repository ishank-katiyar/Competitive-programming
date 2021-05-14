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

int main()
{
 ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
 int t;
 cin >> t;
 while(t--) {
  __int64 n , k;
  cin >> n >> k;
  vector<__int64> a(n);
  for(auto& i : a) cin >> i , i = k - i % k , i %= k;
  sort(a.begin() , a.end());
  if(a[n - 1] == 0) {
   cout << "0" << '\n';
   continue;
  }
  debug(a);
 // map<int, int> mp;
  __int64 ans = 0;
  ans += a[0];
  vector<__int64> b(a);
  for(int i = 1; i < n; i++) {
   if(a[i] == 0) continue;
   //while(mp.count(a[i])) a[i] += k;
   //ans = max(ans , a[i] - 1);
   //mp[a[i]]++;
   if(a[i] == a[i - 1]) b[i] = b[i - 1] + k;
   ans = max(ans , b[i]);
  }
  debug(a);
  cout << ans + 2 << '\n';
 }
 return 0;
}
