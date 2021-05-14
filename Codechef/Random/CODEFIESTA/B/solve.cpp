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
  long long n, m;
  cin >> n >> m;
  long long ans = 0;
  while(m--) {
   long long l, r, value;
   cin >> l >> r >> value;
   ans += (r - l + 1) * value;
  } 
  cout << ans << '\n';
 }
}
