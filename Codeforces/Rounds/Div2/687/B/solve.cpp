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
  int k;
  cin >> k;
  vector<int> a (n);
  set<int> c;
  for (int i = 0; i < n; i++) {
   cin >> a[i];
   c.insert (a[i]);
  }
  int ans = INT_MAX;
  for (auto& i: c) {
   int cur_ans = 0;
   int si = -1, ei = -1;
   int idx = 0;
   while (idx < n) {
    if (a[idx] != i) {
     si = idx;
     ei = si + k - 1;
     cur_ans++;
     idx = ei + 1;
    }
    else idx++;
   }
   ans = min (cur_ans, ans);
  }
  cout << ans << '\n';
 }
 return 0;
}
