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
  for (auto& i: a) cin >> i;
  reverse (a.begin(), a.end());
  for (int i = 0; i < n; i++) {
   if (i < (n / 2)) cout << -a[i] << ' ';
   else cout << a[i] << ' ';
  }
  cout << '\n';
 }
 return 0;
}
