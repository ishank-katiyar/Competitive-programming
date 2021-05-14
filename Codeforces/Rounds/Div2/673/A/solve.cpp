#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int t;
 cin >> t;
 while (t--) {
  int n;
  cin >> n;
  int k;
  cin >> k;
  vector<int> a(n);
  for (auto& i: a) cin >> i;
  int ans = 0;
  sort(a.begin(), a.end());
  for (int i = 1; i < n; i++) {
   int cut_ans = (k - a[i]) / a[0];
   ans += cut_ans;
  }
  cout << ans << '\n';
 }
 return 0;
}
