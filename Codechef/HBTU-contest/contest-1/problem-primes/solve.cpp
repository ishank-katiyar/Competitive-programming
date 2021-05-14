#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int n;
 cin >> n;
 assert (n >= 1 && n <= static_cast <int> (2e5));
 vector<int> a (n);
 const int maxai = static_cast <int> (1e6 + 1);
 vector<int> freq (maxai, 0);
 for (int i = 0; i < n; i++) {
  cin >> a[i];
  freq[a[i]]++;
  assert (a[i] >= 1 && a[i] <= static_cast <int> (1e6));
 }
 sort (a.begin(), a.end());
 a.resize (unique(a.begin(), a.end()) - a.begin());
 n = static_cast<int> (a.size());
 vector<int> c (maxai, 0);
 for (int i = 0; i < n; i++) {
  for (int j = a[i]; j < maxai; j += a[i]) {
   c[j]++;
  }
 }
 vector<int> ans;
 for (int i = 0; i < n; i++) {
  if (c[a[i]] == 1 && freq[a[i]] == 1) {
   ans.push_back (a[i]);
  }
 }
 if (ans.empty() == true) {
  cout << -1 << '\n';
  return 0;
 }
 cout << static_cast <int> (ans.size()) << '\n';
 for (auto& i: ans) cout << i << ' ';
 cout << '\n';
 return 0;
}
