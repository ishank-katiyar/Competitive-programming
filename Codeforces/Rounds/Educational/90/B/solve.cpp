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
  string st;
  cin >> st;
  int cnt = 0;
  stack<char> s;
  for(char ch : st) {
   if(s.empty() == true) s.push(ch);
   else {
    if((s.top() == '0' && ch == '1') || (s.top() == '1' && ch == '0')) {
     s.pop();
     cnt++;
    }
    else s.push(ch);
   }
  }
  cout << ((cnt & 1) ?  "DA" : "NET") << '\n';
 }
 return 0;
}
