#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 cout.tie(0);
 int n;
 cin >> n;
 vector<int> a(n + 1);
 int cnt = 0;
 int mx = 0;
 for (int i = 0; i <= n; i++) {
  cin >> a[i];
  if (a[i] == 1) {
   mx = max (mx, cnt);
   cnt = 0;
  }
  else cnt++;
 }
 vector<int> b(a);
 assert (a[0] == 1);
 mx = max (mx, cnt);
 if (mx <= 1) {
  cout << "perfect\n";
  return 0;
 }
 cout << "ambiguous\n";
 cout << 0 << ' ';
 a[0]--;
 for (int i = 1; i <= n; i++) {
  cout << i << ' ';
  a[i]--;
 }
 for (int i = 1; i <= n; i++) {
  while (a[i]--) cout << i << ' ';
 }
 cout << '\n';
 a = b;
 cout << 0 << ' ';
 a[0]--;
 for (int i = 1; i <= n; i++) {
  cout << i << ' ';
  a[i]--;
 }
 int node = n + 2;
 for (int i = 1; i <= n; i++) {
  if (a[i - 1] > 0 && a[i] > 0) {
   cout << i - 1 << ' ' << node << ' ';
   a[i - 1]--;
   a[i]--;
   node += 2;
   break;
  }
 }
 for (int i = 1; i <= n; i++) {
  while (a[i]--) cout << i << ' ';
 }
 cout << '\n';
 return 0;
}
