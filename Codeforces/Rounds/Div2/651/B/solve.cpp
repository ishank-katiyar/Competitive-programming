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
 int t;
 cin >> t;
 while(t--) {
  int n;
  cin >> n;
  n *= 2;
  vector<pair<int , int>> odd , even;
  for(int i = 1; i <= n; i++) {
   int x;
   cin >> x;
   if(x & 1) odd.emplace_back(x , i);
   else even.emplace_back(x , i);
  }
  if((int) odd.size() & 1) {
   odd.pop_back();
   even.pop_back();
  }
  else {
   if((int) odd.size() >= 2) {
    odd.pop_back();
    odd.pop_back();
   }
   else if((int) even.size() >= 2) {
    even.pop_back();
    even.pop_back();
   }
  }
  while(odd.empty() == false) {
   cout << odd.back().second << ' ';
   odd.pop_back();
   cout << odd.back().second << '\n';
   odd.pop_back();
  }
  while(even.empty() == false) {
   cout << even.back().second << ' ';
   even.pop_back();
   cout << even.back().second << '\n';
   even.pop_back();
  }
 }
 return 0;
}
