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
  string s;
  cin >> s;
  int n = (int) s.size();
  vector<int> a(n);
  __int64 ans = 0;
  __int64 bal = 0;
  __int64 mn = 0;
  for(int i = 0; i < n; i++) {
   if(s[i] == '+') bal++;
   else bal--;
   if(bal < mn) {
    ans += i + 1;
    mn = bal;
   }
  }
  ans += n;
  cout << ans << '\n';
 }
 return 0;
}
