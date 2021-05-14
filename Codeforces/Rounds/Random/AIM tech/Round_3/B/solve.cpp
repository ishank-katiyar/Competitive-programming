#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int n;
 cin >> n;
 int x;
 cin >> x;
 vector<int> a(n);
 for (int i = 0; i < n; i++) {
  cin >> a[i];
 }
 if (n == 1) {
  cout << 0 << '\n';
  return 0;
 }
 sort (a.begin(), a.end());
 if (x < a[0]) {
  cout << a[0] - x + a[n - 2] - a[0] << '\n';
  return 0;
 }
 if (x > a[n - 1]) {
  cout << x - a[n - 1] + a[n - 1] - a[1] << '\n';
  return 0;
 }
 int ans1 = a[n - 2] - a[0] + min ((int) abs(x - a[0]), (int) abs(x - a[n - 2]));
 int ans2 = a[n - 1] - a[1] + min ((int) abs(x - a[1]), (int) abs(x - a[n - 1]));
 cout << min (ans1, ans2) << '\n';
 return 0;
}
