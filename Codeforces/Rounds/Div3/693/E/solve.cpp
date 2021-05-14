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
    cin >> a[i].first.first >> a[i].first.second;
    a[i].second = i + 1;
  }
  sort (a.begin(), a.end(), [](const auto A, const auto B) -> bool {
   if (A.first.first == B.first.first) return A.first.second < B.first.second;
   return A.first.first < B.first.first;
  });
  vector<int> ans (n + 1, -1);
  map<int, int> mp;
  for (int i = 0; i < n; i++) {
   if (mp.empty() == false) {
    int x = mp.begin()->first;
    int idx = mp.begin()->second;
    if (a[i].first.second > x) ans[a[i].second] = idx;
   }
   if (a[i].first.first != a[i + 1].first.first) {
    int j = i;
    while (j >= 0 && a[j].first.first == a[i].first.first) mp[a[j].first.second] = a[j].second, j--;
   }
  }
  vector<int> A (n);
  for (int i = 0; i < n; i++) A[i] = a[i].first.first;
  mp.clear();
  for (int i = 0; i < n; i++) {
   if (mp.count (a[i].first.second) == 0) mp[a[i].first.second] = a[i].second;
  }
  vector<int> pre_min (n);
  pre_min [0] = a[0].first.second;
  for (int i = 1; i < n; i++) {
   pre_min [i] = min (pre_min[i - 1], a[i].first.second);
  }
  for (int i = 0; i < n; i++) {
   int x = a[i].first.first;
   int y = a[i].first.second;
   int idx = lower_bound (A.begin(), A.end(), y) - A.begin();
   idx--;
   if (idx >= 0) {
    assert (a[idx].first.first < y);
    int mn = pre_min [idx];
    if (mn < x) {
     ans[a[i].second] = mp[mn];
    }
   }
  }
  for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
  cout << '\n';
 }
 return 0;
}
