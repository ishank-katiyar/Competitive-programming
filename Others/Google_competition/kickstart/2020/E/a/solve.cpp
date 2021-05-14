#include <bits/stdc++.h>
using namespace std;

void solve() {
 int n;
 cin >> n;
 vector<int> a(n);
 for(auto& i: a) cin >> i;
 vector<int> diff;
 for(int i = 1; i < n; i++) diff.push_back(a[i] - a[i-1]);
 int ans = 1;
 int cur = 1;
 for(int i = 1; i < n-1; i++) {
  if(diff[i] == diff[i-1]) cur++;
  else cur = 1;
  ans = max(ans, cur);
 }
 cout << ans + 1 << '\n';
}

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int t;
 cin >> t;
 for(int tt = 1; tt <= t; tt++) {
  cout << "Case #" << tt << ": ";
  solve();
 }
}
