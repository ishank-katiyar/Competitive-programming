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
 string ans = "";
 int diff;
 if (a[0].first <= 500) {
  ans += 'A';
  diff = a[0].first;
 }
 else {
  ans += 'G';
  diff = -a[0].second;
 }
 for (int i = 1; i < n; i++) {
  if (diff + a[i].first <= 500) {
   ans += 'A';
   diff += a[i].first;
  }
  else {
   diff -= a[i].second;
   assert (diff <= 500 && diff >= -500);
   ans += 'G';
  }
 }
 cout << ans << '\n';
 return 0;
}
