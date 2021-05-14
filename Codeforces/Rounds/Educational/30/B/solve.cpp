#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int n;
 cin >> n;
 string s;
 cin >> s;
 int diff = 0;
 map<int, int> mp;
 mp[0] = 0;
 int ans = 0;
 for (int i = 1; i <= n; i++) {
  if (s[i - 1] == '0') diff--;
  else diff++;
  if (mp.count (diff)) {
   ans = max(ans, i - mp[diff]); 
  }
  else mp[diff] = i;
 }
 cout << ans << '\n';
 return 0;
}
