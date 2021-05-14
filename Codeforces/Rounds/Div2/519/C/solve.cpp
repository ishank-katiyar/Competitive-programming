#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 string s;
 cin >> s;
 string ss = s;
 int n = (int) s.size();
 if (n == 1) {
  cout << 0 << '\n';
  return 0;
 }
 vector<int> ans(n);
 auto rev = [&] (int i) -> void {
  string S = s.substr(0, i + 1);
  reverse(S.begin(), S.end());
  for (int j = 0; j <= i; j++) {
   s[j] = S[j];
  }
 };
 for (int i = 0; i < n - 1; i++) {
  if (s[i] != s[i + 1]) ans[i] = 1, rev(i);
 }
 //cerr << s << '\n';
 if (ss[n - 1] == 'a') ans[n - 1] = 1, rev(n - 1);
 //cerr << s << '\n';
 bool ok = true;
 for (int i = 1; i < n; i++) ok &= (s[i] >= s[i - 1]);
 //cout << ok << '\n';
 assert (ok == true);
 for (auto& i: ans) cout << i << ' ';
 cout << '\n';
 return 0;
}
