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
  int n;
  cin >> n;
  int a = 0 , b = 0;
  while(n % 2 == 0) a++ , n /= 2;
  while(n % 3 == 0) b++ , n /= 3;
  if(n != 1 || a > b) {
   cout << "-1" << '\n';
   continue;
  }
  int moves = 0;
  moves += b - a + b;
  cout << moves << '\n';
 }
 return 0;
}
