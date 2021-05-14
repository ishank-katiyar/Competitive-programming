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
  int n , k;
  cin >> n >> k;
  deque<__int64> a;
  for(int i = 0; i < n; i++) {
   int x;
   cin >> x;
   a.push_back(x);
  }
  sort(a.begin() , a.end());
  vector<int> w(k);
  for(int& i : w) cin >> i;
  sort(w.rbegin() , w.rend());
  __int64 ans = 0;
  for(int& i : w) {
   if(i == 1) {
     ans += 2 * a[n - 1];
     n--;
     a.pop_back();
     k--;
   }
   else {
    ans += a[0];
    i--;
    while(i--) a.pop_front() , n--;
   }
  }
  assert(n == k);
  ans += accumulate(a.begin() , a.end() , 0LL);
  cout << ans << '\n';
 }
 return 0;
}
