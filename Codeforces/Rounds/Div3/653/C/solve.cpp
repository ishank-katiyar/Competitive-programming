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
  string s;
  cin >> s;
  int bal = 0 , ans = 0;
  for(char ch : s) {
   if(ch == ')') bal--;
   else bal++;
   if(bal < 0) ans++ , bal++;
  }
  //assert(bal == 0);
  cout << ans << '\n';
 }
 return 0;
}
