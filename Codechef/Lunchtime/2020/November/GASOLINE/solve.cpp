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
  vector<pair<long long, long long>> a (n);
  for (int i = 0; i < n; i++) {
   cin >> a[i].second;
  }
  for (int i = 0; i < n; i++) {
   cin >> a[i].first;
  }
  long long total = n;
  long long ans = 0;
  sort (a.begin(), a.end(), [] (const pair<long long, long long> A, const pair<long long, long long> B) {
   if (A.first != B.first) return A.first < B.first;
   return A.second > B.second;
  });
  for (int i = 0; i < n; i++) {
   if (total == 0) break;
   long long x = min (total, a[i].second);
   ans += a[i].first * x;
   total -= x;
  }
  cout << ans << '\n';
 }
 return 0;
}
