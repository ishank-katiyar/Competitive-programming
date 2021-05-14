#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
 #include <bits/debugger.hpp>
 // #define __int64 __int64_t
#else 
 #define debug(a...) //
#endif

#define __int64 long long int 

string s = "abcdefghijklmnopqrstuvwxyz";

int main()
{
 ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
 __int64 n;
 cin >> n;
 string ans = "";
 while(n) {
  int mm = ((n % 26 - 1) + 26) % 26;
  ans += s[mm];
  n -= mm;
  n /= 26;
 }
 reverse(ans.begin() , ans.end());
 cout << ans << '\n';
 return 0;
}
