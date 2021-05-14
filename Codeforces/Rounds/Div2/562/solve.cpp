#include <bits/stdc++.h>

using namespace std;

const int maxn = 3e5 + 1;
vector<int> degree(maxn, 0);

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int n, m;
 cin >> n >> m;
 map<pair<int, int>, int> mp;
 for (int i = 0; i < m; i++) {
  int x, y;
  cin >> x >> y;
  if (x > y) swap(x, y);
  mp[make_pair(x, y)]++;
  degree[x]++, degree[y]++;
 }
 vector<pair<int, int>> a;
 for (int i = 1; i < maxn; i++) {
  if (degree[i] > 0) a.emplace_back(degree[i], i);
 }
 sort(a.begin(), a.end());
 int sz = (int) a.size();
 for (int i = sz - 1; i >= 0; i--) {
  int rem = m - a[i].first;
  auto it = lower_bound(a.begin(), a.end(), make_pair(rem, INT_MIN));
  if (it == a.end()) break;
  int idx = it - a.begin();
  for (int j = idx; j < sz; j++) {
   if (i == j) continue;
   pair p = make_pair(min(a[i].second, a[j].second), max(a[i].second, a[j].second));
   int total = a[i].first + a[j].first - mp[p];
   if (total >= m) {
    cout << "YES" << '\n';
    return 0;
   }
  }
 } 
 cout << "NO" << '\n';
 return 0;
}
