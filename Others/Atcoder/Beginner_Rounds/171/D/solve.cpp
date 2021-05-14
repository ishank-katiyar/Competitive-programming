#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
 #include <bits/debugger.hpp>
 // #define __int64 __int64_t
#else 
 #define debug(a...) //
#endif

#define __int64 long long int

const int maxa = 1e5 + 1;
vector<int> c(maxa , 0);

int main()
{
 ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
 int n;
 cin >> n;
 __int64 sum = 0; 
 for(int i = 0; i < n; i++) {
  int x;
  cin >> x;
  sum += x;
  c[x]++;
 }
 int q;
 cin >> q;
 while(q--) {
  int b , c1;
  cin >> b >> c1;
  int cnt = c[b];
  sum += (c1 - b) * cnt;
  c[b] = 0;
  c[c1] += cnt;
  cout << sum << '\n';
 }
 return 0;
}
