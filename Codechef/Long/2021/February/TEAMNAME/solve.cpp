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

  vector<string> s (n);

  map <char, vector<string>> mp;

  for (int i = 0; i < n; i++) {
   cin >> s[i];

   mp[s[i][0]].push_back (s[i]);
  }

  int64_t ans = 0;

  for (int a = 0; a < 26; a++) {
   for (int b = a + 1; b < 26; b++) {
    set<string> S;
    for (auto &i : mp[a + 'a']) {
     S.insert (string(i.begin() + 1, i.end()));
    }
    for (auto &i : mp[b + 'a']) {
     S.insert (string(i.begin() + 1, i.end()));
    }
    int64_t sz1 = static_cast <int> (mp[a + 'a'].size());
    int64_t sz2 = static_cast <int> (mp[b + 'a'].size());
    int common = sz1 + sz2 - static_cast <int> (S.size());
    sz1 -= common;
    sz2 -= common;
    ans += (sz1 * sz2);
   }
  }
  cout << ans * 2 << '\n';
 }
 return 0;
}
