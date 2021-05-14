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
  vector <pair<int64_t, int>> a (n);
  for (int i = 0; i < n; i++) {
   cin >> a[i].first;
   a[i].second = i + 1;
  }
  sort (a.begin(), a.end());
  vector<int64_t> pre(n);
  pre[0] = a[0].first;
  for (int i = 1; i < n; i++)  {
   pre[i] += pre[i - 1] + a[i].first;
  }
  vector<int> ans;
  ans.push_back (a[n - 1].second);
  for (int i = n - 2; i >= 0; i--) {
   if (pre[i] >= a[i + 1].first) {
    ans.push_back (a[i].second);
   } else {
    break;
   }
  }
  sort (ans.begin(), ans.end());
  cout << static_cast <int> (ans.size()) << '\n';
  for (auto& i: ans) cout << i << ' ';
  cout << '\n';
 }
 return 0;
}
