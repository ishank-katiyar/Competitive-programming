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
  int x , y , n;
  cin >> x >> y >> n;
  if(n % x < y) n -= y; 
  n -= (n % x);
  n += y;
  //n %= x;
 cout << n << '\n';
 }
 return 0;
}
