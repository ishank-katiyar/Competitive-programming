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
  int sum = 0;
  int cnt1 = 0;
  int cnt2 = 0;
  for (int i = 0; i < n; i++) {
   cin >> a[i];
   sum += a[i];
   cnt1 += (a[i] == 1);
  }
  if (sum % 2 == 1) {
   cout << "NO" << '\n';
   continue;
  }
  sum /= 2;
  cnt2 = n - cnt1;
  int x = sum / 2;
  int mn = min (cnt2, x);
  sum -= 2 * mn;
  cnt2 -= mn;
  cout << (sum <= cnt1 ? "YES": "NO") << '\n';
 }
 return 0;
}
