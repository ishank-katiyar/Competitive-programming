#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int n, m;
 cin >> n >> m;
 string s, t;
 cin >> s >> t;
 vector<int> pre (m);
 int i = 0, j = 0;
 while (i < n && j < m) {
  if (s[i] == t[j]) {
   pre[j] = i;
   i += 1;
   j += 1;
  } else {
   i += 1;
  }
 } 
 assert (j == m);
 vector<int> suf (m);
 i = n - 1, j = m - 1;
 while (i >= 0 && j >= 0) {
  if (s[i] == t[j]) {
   suf[j] = i;
   i -= 1;
   j -= 1;
  } else {
   i -= 1;
  }
 }
 assert (j == -1);
 int ans = 0;
 for (int I = 0; I < m - 1; I++) {
  ans = max (ans, suf[I + 1] - pre[I]);
 }
 // assert (ans > 0);
 cout << ans << '\n';
 return 0;
}
