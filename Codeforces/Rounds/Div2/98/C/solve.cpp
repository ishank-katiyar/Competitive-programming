#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int n;
 cin >> n;
 vector<pair<int, int>> a(n);
 for (auto& i: a) cin >> i.first >> i.second;
 sort (a.begin(), a.end());
 set<int> s;
 s.insert (a[0].second);
 int ans = 0;
 for (int i = 1; i < n; i++) {
  int x = a[i].second;
  auto it = s.upper_bound(x);
  ans += (it != s.end());
  s.insert (x);
 }
 cout << ans << '\n';
 return 0;
}
