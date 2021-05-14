#include <bits/stdc++.h>
using namespace std;

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int n;
 cin >> n;
 if (n == 1) {
  cout << 1 << '\n';
  return 0;
 }
 string s;
 cin >> s;
 set<char> ss(s.begin(), s.end());
 int tt = (int) ss.size();
 ss.clear();
 map<char, int> st;
 st[s[0]]++;
 ss.insert(s[0]);
 int j = 0;
 int ans = 1e9;
 for (int i = 1; i < n; i++) {
  st[s[i]]++;
  ss.insert(s[i]);
  while (st[s[j]] > 1) j++, st[s[j - 1]]--;
  if ((int) ss.size() == tt) ans = min (ans, i - j + 1);
 }
 cout << ans << '\n';
 return 0;
}
