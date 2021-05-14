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
  vector<int> a (n);
  for (int i = 0; i < n; i++) {
   cin >> a[i];
  }
  vector<int> pre (n), suf (n);
  int mn = INT_MAX;
  pre[0] = a[0] - 1;
  mn = pre[0];
  for (int i = 1; i < n; i++) {
   mn = min (mn, a[i] - i - 1);
   pre[i] = mn;
  }
  mn = suf[n - 1] = a[n - 1] + n;
  for (int i = n - 2; i >= 0; i--) {
   mn = min (mn, a[i] + i + 1);
   suf[i] = mn;
  }
  for (int i = 0; i < n; i++) {
   cout << min (pre[i] + i + 1, suf[i] - i - 1) << ' ';
  }
  cout << '\n';
 }
 return 0;
}
