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
  vector<int> a(n);
  for (auto& i: a) cin >> i;
  int ans = -1;
  int x = *max_element(a.begin(), a.end());
  for (int i = 0; i < n; i++) {
   if (i > 0 && a[i - 1] < a[i] && a[i] == x) {
    ans = i + 1;
    break;
   }
   else if (i < n - 1 && a[i] > a[i + 1] && a[i] == x) {
    ans = i + 1;
    break;
   }
  }
  cout << ans << '\n';
 }
 return 0;
}
