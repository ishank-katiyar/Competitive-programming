#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int t;
 cin >> t;
 while (t--) {
  int n;
  cin >> n;
  if (n == 1) {
   cout << 1 << '\n';
   continue;
  }
  if (!(n & (n - 1))) {
   cout << -1 << '\n';
   continue;
  }
  vector<int> a(n + 1);
  a[1] = 2;
  a[2] = 3;
  a[3] = 1;
  for (int i = 4; i <= n; i++) {
   if (!(i & (i - 1))) {
    assert (i != n);
    a[i + 1] = i;
    a[i] = i + 1;
    i++;
   }
   else a[i] = i;
  }
  for (int i = 1; i <= n; i++) cout << a[i] << ' ';
  for (int i = 1; i < n; i++) {
   assert ((a[i] & a[i + 1]) > 0);
  }
  cout << '\n';
 }
 return 0;
}
