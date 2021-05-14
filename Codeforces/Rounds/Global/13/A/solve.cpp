#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int n, q;
 cin >> n >> q;
 vector<int> a (n);
 int cnt = 0;
 for (int i = 0; i < n; i++) {
  cin >> a[i];
  cnt += a[i];
 }
 while (q--) {
  int t;
  cin >> t;
  if (t == 1) {
   int x;
   cin >> x;
   x--;
   if (a[x]) {
    a[x] = 0;
    cnt--;
   } else {
    a[x] = 1;
    cnt++;
   }
  } else {
   int k;
   cin >> k;
   cout << (k <= cnt ? 1 : 0) << '\n';
  }
 }
 return 0;
}
