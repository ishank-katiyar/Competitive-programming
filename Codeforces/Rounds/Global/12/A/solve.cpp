#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int cnt = 0;
  string ans = "";
  for (int i = 0; i < n; i++) {
   if (s[i] == 'b') cnt++;
   else ans += s[i];
  }
  cout << string (cnt, 'b') + ans << '\n';
 }
 return 0;
}
