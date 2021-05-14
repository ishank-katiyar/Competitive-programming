#ifdef LOCAL
 #include <P.hpp>
 #include <debugger.hpp>
 #define __int64 __int64_t
#else 
 #include <bits/stdc++.h>
 #define debug(a...) //
 #define __int64 long long int
#endif
using namespace std;

int main()
{
 ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
 __int64 n , m , k;
 cin >> n >> m >> k;
 vector<__int64> s;
 __int64 sum = 0;
 for(int i = 0; i < n; i++) {
  __int64 x;
  cin >> x;
  sum += x;
  s.emplace_back(sum);
 }
 sum = 0;
 __int64 ans = 0;
 ans = upper_bound(s.begin() , s.end() , k) - s.begin();
 debug(ans);
 for(__int64 i = 0; i < m; i++) {
  __int64 y;
  cin >> y;
  if(sum > k) break;
  sum += y;
  if(sum > k) break;
  debug(ans , sum);
  ans = max(ans , i + 1 + (__int64)( upper_bound(s.begin() , s.end() , k - sum) - s.begin()));
 }
 cout << ans << '\n';
 return 0;
}
