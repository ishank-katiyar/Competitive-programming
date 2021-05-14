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
  string p;
  cin >> p;
  if (count (s.begin(), s.end(), '1') != count (p.begin(), p.end(), '1')) {
   cout << "No" << '\n';
   continue;
  }
  set<int> idx;
  for (int i = 0; i < n; i++) {
   if (s[i] == '1' && p[i] == '1') {
    s[i] = p[i] = '0';
   }
   if (s[i] == '1' && p[i] == '0') idx.insert (i);
  }
  bool ok = true;
  for (int i = n - 1; i >= 0; i--) {
   if (p[i] == '1') {
    assert (s[i] == '0');
    auto it = idx.lower_bound (i);
    if (it == idx.begin()) {
     ok = false;
     break;
    }
    it--;
    s[*it] = '0';
    s[i] = '1';
    idx.erase (it);
   }
  }
  cout << (ok ? "Yes" : "No") << '\n';
 }
 return 0;
}
