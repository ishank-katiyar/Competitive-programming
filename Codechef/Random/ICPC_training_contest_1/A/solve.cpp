#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) { 
  int64_t n;
  cin >> n;
  int64_t ans = INT_MAX;
  string s = to_string (n);
  for (int i = 0; i < static_cast <int> (s.size()); i++) {
   int64_t cur_ans = static_cast <int64_t> (stoll (s.substr (0, i) + s.substr (i + 1)));
   ans = min (ans, cur_ans);
  }
  cout << ans << '\n';
 }
 return 0;
}
