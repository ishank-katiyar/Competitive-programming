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
 vector<__int64> fib({0 , 1});
 __int64 a = 0 , b = 1;
 while(b <= (int) 1e9) {
  fib.emplace_back(a + b);
  __int64 c = a + b;
  a = b;
  b = c;
 }
 __int64 n;
 cin >> n;
 int sz = (int) fib.size();
 vector<__int64> ans;
 for(int i = sz - 1; i >= 1; i--) {
  while(fib[i] <= n){
   n -= fib[i];
   debug(n , fib[i]);
   ans.emplace_back(fib[i]);
  }
 }
 debug(ans);
 assert((int) ans.size() <= 3);
 while(ans.size() != 3) ans.emplace_back(0);
 for(__int64 i : ans) cout << i << ' ';
 cout << '\n';
 return 0;
}
