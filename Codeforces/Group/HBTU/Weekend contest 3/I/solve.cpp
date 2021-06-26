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
 int t;
 cin >> t;
 while(t--) {
  int n;
  cin >> n;
  int cnt = 0;
  for(int i = 0; i < n; i++) {
   int x;
   cin >> x;
   if(x & 1) cnt++;
  }
  if(cnt == n || cnt == 0) cout << "YES" << '\n';
  else cout << "NO" << '\n';
 }
 return 0;
}
