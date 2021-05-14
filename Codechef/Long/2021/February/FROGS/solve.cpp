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
  vector <pair<int, pair<int, int>>> a (n);
  for (int i = 0; i < n; i++) {
   cin >> a[i].first;
  }
  for (int i = 0; i < n; i++) {
   a[i].second.first = i + 1;
   cin >> a[i].second.second;
  }
  sort (a.begin(), a.end());
  int ans = 0;
  for (int i = 1; i < n; i++) {
   if (a[i].second.first <= a[i - 1].second.first) {
    int dif = a[i - 1].second.first - a[i].second.first;
    int cnt = (dif / a[i].second.second) + 1;
    ans += cnt;
    a[i].second.first += cnt * a[i].second.second;
   }
  }
  cout << ans << '\n';
 }
 return 0;
}
