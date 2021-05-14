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
 int n , k;
 cin >> n >> k;
 vector<int> a(n);
 for(int& i : a) cin >> i;
 sort(a.begin() , a.end());
 int ans = 0;
 for(int i = 0; i < k; i++) ans += a[i];
 cout << ans << '\n';
 return 0;
}
