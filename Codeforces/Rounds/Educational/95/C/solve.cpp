#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int t;
 cin >> t;
 while (t--) {
  int n; 
  cin >> n;
  vector<int> a(n);
  bool ok = true;
  int ans = 0;
  int cur = 0;
  for (auto& i: a) {
   cin >> i;
   if (ok == true) {
    ans += i;
    ok = false;
    continue;
   }
   if (i == 0) {
    ans += cur / 3;
    cur = 0;
   }
   else cur++;
  }
  ans += cur / 3;
  cout << ans << '\n';
 }
 return 0;
}
