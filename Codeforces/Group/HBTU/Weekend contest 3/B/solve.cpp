#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
 #include <bits/debugger.hpp>
#else 
 #define debug(a...) //
 #define __int64 __int64_t
#endif

int main()
{
 ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
 int n;
 cin >> n;
 int cnt = 0;
 for(int i = 6; i <= n; i++) {
  int x = i;
  int cur = 0;
  for(int j = 2; j <= sqrt(x); j++) {
   if(x % j) continue;
   cur++;
   while(x % j == 0) x /= j;
  }
  if(x != 1) cur++;
  debug(i , cur);
  cnt += (cur == 2);
 }
 cout << cnt << '\n';
 return 0;
}
