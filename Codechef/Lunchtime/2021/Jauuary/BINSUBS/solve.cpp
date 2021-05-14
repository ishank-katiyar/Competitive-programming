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
  string s;
  cin >> s;
  vector<int> pre (n), suf (n);
  pre[0] = (s[0] == '0');
  for (int i = 1; i < n; i++) {
   pre[i] += pre[i - 1] + (s[i] == '0');
  }
  suf[n - 1] = (s[n - 1] == '1');
  for (int i = n - 2; i >= 0; i--) {
   suf[i] += suf[i + 1] + (s[i] == '1');
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
   ans = max (ans, pre[i] + suf[i]);
  }
  cout << n - ans << '\n';
 }
 return 0;
}
