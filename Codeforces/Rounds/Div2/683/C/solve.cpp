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
  long long W;
  cin >> W;
  vector<pair<long long, int>> a (n);
  for (int i = 0; i < n; i++) {
   cin >> a[i].first;
   a[i].second = i + 1;
  }
  vector<long long> A (n);
  for (int i = 0; i < n; i++) {
   A[i] = a[i].first;
  }
  sort (a.rbegin(), a.rend());
  vector<int> ans;
  long long sum = 0;
  for (int i = 0; i < n; i++) {
   sum += a[i].first;
   ans.push_back (a[i].second);
   if (sum > W) {
    sum -= a[i].first;
    ans.pop_back ();
   }
  }
  sum = 0;
  for (auto& i: ans) {
   sum += A[i - 1];
  }
  if (sum >= ((W + 1) / 2) && sum <= W)  {
   cout << (int) ans.size() << '\n';
   for (auto& i: ans) cout << i << ' ';
   cout << '\n';
   continue;
  }
  cout << -1 << '\n';
 }
 return 0;
}
