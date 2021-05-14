#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int test_case;
 cin >> test_case;
 for (int tt = 1; tt <= test_case; tt++) {
  cout << "Case #" << tt << ": ";
  string s;
  cin >> s;
  long long ans = 0;
  long long cnt = 0;
  int n = (int) s.size();
  for (int i = 3; i < n; i++) {
   if (s.substr(i - 3, 4) == "KICK") {
    cnt++;
   }
   if (i > 3 && s.substr(i - 4, 5) == "START") {
    ans += cnt;
   }
  }
  cout << ans << '\n';
 }
 return 0;
}
