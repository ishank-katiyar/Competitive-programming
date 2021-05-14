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
  int n, x;
  cin >> n >> x;
  vector<int> a(n);
  for (auto& i: a) cin >> i;
  set<int> s(a.begin(), a.end());
  if ((int) s.size() == 1 && *s.begin() == x) {
   cout << 0 << '\n';
   continue;
  }
  int cnt = 0, sum = 0;
  for (int i = 0; i < n; i++) {
   if (a[i] != x) {
    cnt++, sum += a[i];
   }
  }
  if (sum == cnt * x || cnt < n) {
   cout << 1 << '\n';
  }
  else cout << 2 << '\n';
 }
 return 0;
}
