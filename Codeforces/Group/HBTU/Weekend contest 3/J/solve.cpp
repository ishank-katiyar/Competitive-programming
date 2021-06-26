#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
 #include <bits/debugger.hpp>
 #define __int64 __int64_t
#else 
 #define debug(a...) //
#endif

const int maxn = 1e6 + 1;
vector<int> a(maxn , 0);
vector<set<int>> b(maxn);

int sf(int n) {
 for(int i = 2; i <= sqrt(n); i++) if(n % i == 0) return i;
 return n;
}

int main()
{
 ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
 vector<int> aa;
 for(int i = 0; i <= maxn; i++) {
  aa.emplace_back(i);
 }
 aa[0] += 1431;
 return 0;
}
