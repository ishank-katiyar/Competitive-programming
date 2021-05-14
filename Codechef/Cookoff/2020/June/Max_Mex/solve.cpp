#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
 #include <bits/debugger.hpp>
 #define __int64 __int64_t
#else 
 #define debug(a...) //
#endif

const int maxn = 1e5 + 1;
vector<int> c(maxn , 0);

int main()
{
 ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
 int t;
 cin >> t;
 while(t--) {
  int n , m;
  cin >> n >> m;
  for(int i = 1; i < m; i++) c[i] = 0;
  int cnt = 0;
  for(int i = 0; i < n; i++) {
   int x;
   cin >> x;
   if(x < m) c[x]++;
   if(x > m) cnt++;
  }
  bool ok = true;
  int sum = 0;
  for(int i = 1; i < m; i++) ok &= (c[i] > 0) , sum += c[i];
  if(ok == false) {
   cout << "-1" << '\n';
  }
  else cout << sum + cnt << '\n';
 }
 return 0;
}
