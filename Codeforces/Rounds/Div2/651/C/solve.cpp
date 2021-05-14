#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
 #include <bits/debugger.hpp>
 #define __int64 __int64_t
#else 
 #define debug(a...) //
#endif

bool is_prime(int n) {
 for(int i = 2; i <= sqrt(n); i++) if(n % i == 0) return false;
 return true;
}

int main()
{
 ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
 int t;
 cin >> t;
 while(t--) {
  int n;
  cin >> n;
  if(n == 1) {
   cout << "FastestFinger" << '\n';
   continue;
  }
  if(n == 2) {
   cout << "Ashishgup" << '\n';
   continue;
  }
  if(n & 1) {
   cout << "Ashishgup" << '\n';
   continue;
  }
  int cnt = 0;
  while(n % 2 == 0) cnt++ , n /= 2;
  if(n == 1) {
   cout << "FastestFinger" << '\n';
   continue;
  }
  if(cnt == 1) {
   if(is_prime(n)) {
    cout << "FastestFinger" << '\n';
   }
   else cout << "Ashishgup" << '\n';
  }
  else {
  cout << "Ashishgup" << '\n';
  }
 }
 return 0;
}
