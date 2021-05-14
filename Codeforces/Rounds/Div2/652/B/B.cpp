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
  string last = "";
  string first = "";
  while(s.empty() == false && s.back() == '1') s.pop_back() , last += '1';
  reverse(s.begin() , s.end());
  while(s.empty() == false && s.back() == '0') s.pop_back() , first += '0';
  reverse(s.begin() , s.end());
  debug(s);
  int cnt = 0;
  int sz = (int) s.size();
  for(int i = 1; i < sz; i++) if(s[i] != s[i - 1]) cnt++;
  if(cnt > 0) {
   first += '0';
  }
  first += last;
  cout << first << '\n';
 }
 return 0;
}
