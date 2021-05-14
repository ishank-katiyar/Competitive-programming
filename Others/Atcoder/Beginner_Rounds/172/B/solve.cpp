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
 string s , t;
 cin >> s >> t;
 int n = (int) s.size();
 int cnt = 0;
 for(int i = 0; i < n; i++) if(s[i] != t[i]) cnt++;
 cout << cnt << '\n';
 return 0;
}
