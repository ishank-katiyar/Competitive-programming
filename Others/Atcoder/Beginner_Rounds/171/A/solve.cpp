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
 char ch;
 cin >> ch;
 cout << (islower(ch) ? 'a' : 'A') << '\n';
 return 0;
}
