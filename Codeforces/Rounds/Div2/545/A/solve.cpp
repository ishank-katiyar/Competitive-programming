#include <bits/stdc++.h>
using namespace std;

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int n;
 cin >> n;
 vector<int> a(n);
 for(auto& i: a) cin >> i;
 int prev = -1;
 int cur = 1;
 int ans = 2;
 for(int i = 1; i < n; i++) {
  if(a[i] == a[i-1]) cur++;
  else {
   prev = cur;
   cur = 1;
  }
  ans = max (ans, 2 * min(prev, cur));
 }
 cout << ans << '\n';
}
