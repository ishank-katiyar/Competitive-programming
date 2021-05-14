#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
 #include <bits/debugger.hpp>
 #define __int64 __int64_t
#else 
 #define debug(a...) //
#endif

const int maxn = 5e3 + 1;
vector<int> c(maxn , 0);

int main()
{
 ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
 int t;
 cin >> t;
 while(t--) {
  int n , b , m;
  cin >> n >> b >> m;
  for(int i = 0; i < n; i++) {
   c[i] = i / b;
  }
  int prev = -1 , cnt = 0;
  for(int i = 1; i <= m; i++) {
   int x;
   cin >> x;
   if(c[x] != prev) cnt++;
   prev = c[x];
  }
  cout << cnt << '\n';
 }
 return 0;
}
