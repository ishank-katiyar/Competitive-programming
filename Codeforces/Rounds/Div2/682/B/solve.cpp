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
  map <int, int> mp;
  for (int i = 0; i < n; i++) {
   cin >> a[i];
   mp[a[i]]++;
  }
  bool ok = false;
  for (auto& i: mp) {
   if (i.second > 1) ok = true;
  }
  cout << (ok ? "YES" : "NO") << '\n';
 }
 return 0;
}
