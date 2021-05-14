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
  bool ok = false;
  for (int i = 0; i < n - 1; i++) {
   ok |= (a[i] < a[i + 1]);
  }
  // vector<int> premin (n);
  // premin[0] = a[0];
  // for (int i = 1; i < n; i++) {
  //  premin[i] = min (premin[i], a[i]);
  // }
  // vector<int> sufmin (n);
  // sufmin.back() = a.back();
  // for (int i = n - 2; i >= 0; i--) {
  //  sufmin[i] = min (sufmin[i + 1], a[i]);
  // }
  // int mn = *min_element (a.begin(), a.end());
  // while (a.empty() == false && a.back() == mn) {
  //  a.pop_back ();
  // }
  // bool ok = count (a.begin(), a.end(), mn) > 0;
  cout << (ok ? "Yes" : "No") << '\n';
 }
 return 0;
}
