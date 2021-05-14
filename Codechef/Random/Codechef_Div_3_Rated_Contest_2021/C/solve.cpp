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
  vector<pair <int, int>> a (n);
  for (int i = 0; i < n; i++) {
   cin >> a[i].first;
   a[i].second = i + 1;
  }
  sort (a.begin(), a.end(), [] (const pair <int, int> A, const pair <int, int> B) -> bool {
   if (A.first != B.first) return A.first > B.first;
   return A.second < B.second;
  });
  vector<int> ans (n + 1);
  for (int i = 0; i < n; i++) {
   ans [a[i].second] = i + 1;
  }
  for (int i = 1; i <= n; i++) {
   cout << ans[i] << ' ';
  }
  cout << '\n';
 }
 return 0;
}
