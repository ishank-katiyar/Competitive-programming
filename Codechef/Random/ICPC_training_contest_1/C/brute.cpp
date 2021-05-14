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
  vector<pair<pair<int, int>, int>> a (n);
  for (int i = 0; i < n; i++) {
   cin >> a[i].first.first >> a[i].first.second >> a[i].second;
  }

  auto intersect = [] (pair<int, int> A, pair<int, int> B) -> bool {
   return (B.first >= A.first && B.first <= A.second) || (B.second >= A.first && B.second <= A.second);
  };

  bool ok = true;
  for (int i = 0; i < n; i++) {
   vector<pair<int, int>> b;
   for (int j = 0; j < n; j++) {
    if (i == j) continue;
    if (intersect (a[i].first, a[j].first) && a[i].second == a[j].second) {
     b.push_back (a[j].first);
    }
   }
   sort (b.begin(), b.end());
   int sz = static_cast <int> (b.size());
   for (int j = 1; j < sz; j++) {
    ok &= (b[j - 1].second < b[j].first);
   }
  }
  cout << (ok ? "YES": "NO") << '\n';
 }
 return 0;
}
