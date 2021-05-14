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
  deque <int> a (n);
  for (int i = 0; i < n; i++) {
   cin >> a[i];
  }
  bool ok = true;
  while (a.empty() == false) {
   if (ok) cout << a.front() << ' ';
   else cout << a.back() << ' ';
   if (ok) a.pop_front();
   else a.pop_back();
   ok ^= 1;
  }
  cout << '\n';
 }
 return 0;
}
