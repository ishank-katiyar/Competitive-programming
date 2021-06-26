#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
 #include <bits/debugger.hpp>
 #define __int64 __int64_t
#else 
 #define debug(a...) //
#endif

int main()
{
 ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
 __int64 a , b;
 cin >> a >> b;
 __int64 cnt = 0;
 while(1) {
  if(a == 0 || b == 0) break;
  if(a < b) swap(a , b);
  cnt += a / b;
  a = a % b;
 }
 cout << cnt << '\n';
 return 0;
}
