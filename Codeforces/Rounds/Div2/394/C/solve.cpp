#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 cout.tie(0);
 int n, m;
 cin >> n >> m;
 vector<string> a(n);
 for (auto& i: a) cin >> i;
 vector<pair<long long int, int>> dig, ch, sy;
 for (int i = 0; i < n; i++) {
  int dd = INT_MAX;
  for (int j = 0; j < m; j++) {
   if (a[i][j] >= '0' && a[i][j] <= '9') {
    dd = min (dd, min (j, m - j));
   }
  }
  int cc = INT_MAX;
  for (int j = 0; j < m; j++) {
   if (a[i][j] >= 'a' && a[i][j] <= 'z') {
    cc = min (cc, min (j, m - j));
   }
  }
  int ss = INT_MAX;
  for (int j = 0; j < m; j++) {
   if (a[i][j] == '#') {
    ss = min (ss, min (j, m - j));
   }
   if (a[i][j] == '*') {
    ss = min (ss, min (j, m - j));
   }
   if (a[i][j] == '&') {
    ss = min (ss, min (j, m - j));
   }
  }
  dig.emplace_back(dd, i);
  ch.emplace_back(cc, i);
  sy.emplace_back(ss, i);
 }
 sort (dig.begin(), dig.end());
 sort (ch.begin(), ch.end());
 sort (sy.begin(), sy.end());
 long long int ans = INT_MAX;
 for (int i = 0; i < n; i++) {
  for (int j = 0; j < n; j++) {
   for (int k = 0; k < n; k++) {
    set<int> s;
    s.insert (dig[i].second);
    s.insert (ch[j].second);
    s.insert (sy[k].second);
    //cerr << (int) s.size() << endl;
    if ((int) s.size() == 3) {
     ans = min (ans, dig[i].first + ch[j].first + sy[k].first);
    }
   }
  }
 }
 assert (ans != INT_MAX);
 cout << ans << '\n';
 return 0;
}
