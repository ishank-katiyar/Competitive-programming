#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
 #include <bits/debugger.hpp>
 // #define __int64 __int64_t
#else 
 #define debug(a...) //
#endif

#define __int64 long long int

int main()
{
 ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
 int n;
 cin >> n;
 vector<__int64> a(n + 1);
 for(int i = 1; i <= n; i++) cin >> a[i];
 __int64 all_xor = 0;
 for(int i = 1; i <= n; i += 2) all_xor ^= (a[i] ^ a[i + 1]);
 for(int i = 1; i <= n; i++) cout << (all_xor ^ a[i]) << ' ';
 cout << '\n';
 return 0;
}
