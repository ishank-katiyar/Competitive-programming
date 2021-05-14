#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int n;
 cin >> n;
 vector<int> a (n);
 for (int i = 0; i < n; i++) {
  cin >> a[i];
 }
 int ans = 0;
 for (int i = 0; i < n; i++) {
  int mn = INT_MAX;
  for (int j = i; j < n; j++) {
   mn = min (mn, a[j]);
   ans = max (ans, mn * (j - i + 1));
  }
 }
 cout << ans << '\n';
 return 0;
}
