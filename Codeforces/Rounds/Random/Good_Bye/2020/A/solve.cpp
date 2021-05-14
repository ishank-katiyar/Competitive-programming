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
  set <int> s;
  for (int i = 0; i < n; i++) {
   for (int j = i + 1; j < n; j++) {
    s.insert (abs (a[i] - a[j]));
   }
  }
  cout << static_cast <int> (s.size()) << '\n';
 }
 return 0;
}
