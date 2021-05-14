#include <bits/stdc++.h>
using namespace std;

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int t;
 cin >> t;
 while(t--) {
  int n, k;
  cin >> n >> k;
  int ans = 0;
  if(k > n) {
   ans += k - n;
  }
  else {
   if((n - k) % 2 == 1) ans = 1;
  }
  cout << ans << '\n';
 }
}
