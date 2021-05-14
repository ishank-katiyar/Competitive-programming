#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  vector<int> a (4);
  for (auto& i: a) cin >> i;
  sort (a.begin(), a.end());
  cout << a[0] * a[2] << '\n';
 }
 return 0;
}
