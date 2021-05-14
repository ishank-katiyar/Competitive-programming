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
  int a, b;
  cin >> a >> b;
  int ans = 0;
  a = a - b;
  if(a < 0) a *= -1;
  for(int i = 10; i >= 1; i--) {
   ans += a / i;
   a %= i;
  }
  cout << ans << '\n';
 }
 return 0;
}
