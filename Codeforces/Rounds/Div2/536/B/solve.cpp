#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int n, m;
 cin >> n >> m;
 vector<int> a(n);
 for (auto& i: a) cin >> i;
 vector<int> c(n);
 for (auto& i: c) cin >> i;
 set<pair<int, int>> s;
 for (int i = 0; i < n; i++) {
  s.insert(make_pair(c[i], i));
 }
 while (m--) {
  int kind, cnt;
  cin >> kind >> cnt;
  kind--;
  long long int cost = 0;
  long long int mn = min(a[kind], cnt);
  a[kind] -= mn;
  cnt -= mn;
  cost += c[kind] * mn;
  while (cnt > 0 && s.empty() == false) {
   pair<int, int> p = *s.begin();
   long long int mn1 = min(a[p.second], cnt);
   a[p.second] -= mn1;
   cnt -= mn1;
   cost += p.first * mn1;
   if (a[p.second] == 0) s.erase(s.begin());
  } 
  if (cnt > 0 && s.empty() == true) cost = 0;
  cout << cost << '\n';
 }
 return 0;
}
