#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 cout.tie(0);
 int n;
 cin >> n;
 string s;
 cin >> s;

 auto f = [] (char c, int x) -> char {
  while (x--) {
   if (c == '9') c = '0';
   else c++;
  } 
  return c;
 };
 
 string ans = s;
 for (int i = 0; i < n; i++) {
  string cur = "";
  if (i == 0) {
   cur = s;
  }
  else cur = s.substr(i) + s.substr(0, i);
  int x = 11;
  while (x--) {
   string ss = cur;
   for (auto& ch: ss) ch = f(ch, x);
   ans = min (ans, ss);
  }
 }
 cout << ans << '\n';
 return 0;
}
