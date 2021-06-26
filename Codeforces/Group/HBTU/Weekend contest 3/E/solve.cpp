#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
 #include <bits/debugger.hpp>
 #define __int64 __int64_t
#else 
 #define debug(a...) //
#endif

const __int64 maxa = (__int64) 1e18 * 5;

__int64 gcd(__int64 a , __int64 b , __int64& x , __int64& y) {
 if(b == 0) {
  x = 1;
  y = 0;
  return a;
 }
 __int64 x1 , y1;
 __int64 gd = gcd(b , a % b , x1 , y1);
 x = y1;
 y = x1 - (a / b) * y1;
 return gd;
} 

int main()
{
 ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
 __int64 a , b , c;
 cin >> a >> b >> c;
 c *= -1;
 if(c % __gcd(a , b)) {
  cout << "-1" << '\n';
  return 0;
 }
 __int64 x , y;
 __int64 gd = gcd(abs(a) , abs(b) , x , y);
 __int64 mul = c / gd;
 x *= mul;
 y *= mul;
 if(a < 0) x *= -1;
 if(b < 0) y *= -1;
 if(x < -maxa || x > maxa || y < -maxa || y > maxa) cout << -1;
 else cout << x << ' ' << y;
 cout << '\n'; 
 return 0;
}
