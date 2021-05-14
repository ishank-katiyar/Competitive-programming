#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 cout.tie(0);
 int n, t;
 cin >> n >> t;
 string s;
 cin >> s;
 set<char> st (s.begin(), s.end());
 if (t > n) {
  string ans = s;
  t -= n;
  while (t--) {
   ans += *st.begin();
  }
  cout << ans << '\n';
  return 0;
 }
 assert ((int) st.size() > 1);
 string ans = s.substr(0, t);
 int idx = -1;
 for (int i = t - 1; i >= 0; i--) {
  if (st.upper_bound(ans[i]) != st.end()) {
   ans[i] = *st.upper_bound(ans[i]);
   idx = i + 1;
   break;
  }
 }
 //for (auto& i: st) cerr << i << ' ';
 //cerr << endl;
 //cerr << idx << endl;
 for (int i = idx; i < t; i++) ans[i] = *st.begin();
 cout << ans << '\n';
 return 0;
}
