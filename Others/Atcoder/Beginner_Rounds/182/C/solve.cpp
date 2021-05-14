#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 string s;
 cin >> s;
 int n = (int) s.size();
 int ans = n;
 for (int mask = 0; mask < (1 << n); mask++) {
  if (__builtin_popcount (mask) == n) continue;
  string cur = "";
  int remove = 0;
  for (int i = 0; i < n; i++) {
   if ((mask >> i) & 1) {
    remove++;
   }
   else {
    cur += s[i];
   }
  }
  long long N = stoll (cur);
  if (N % 3 == 0) {
   ans = min (ans, remove);
  }
 }
 if (ans == n) ans = -1;
 cout << ans << '\n';
 return 0;
}
