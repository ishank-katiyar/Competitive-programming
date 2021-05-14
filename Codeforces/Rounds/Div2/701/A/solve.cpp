#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int64_t a, b;
  cin >> a >> b;
  bool ok = b == 1;
  if (b == 1) b += 1;
  int64_t ans = INT_MAX;
  for (int64_t bb = b; bb <= b + 100; bb++) {
   int64_t cnt = 0;
   int64_t aa = a;
   while (aa > 0) {
    aa /= bb;
    cnt++;
   }
   ans = min (ans, cnt + bb - b);
  }
  cout << ans + ok << '\n';
 }
 return 0;
}
