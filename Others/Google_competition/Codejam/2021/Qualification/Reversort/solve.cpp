#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 for (int tt = 1; tt <= t; tt++) {
  int n;
  cin >> n;
  vector<int> a (n);
  for (int i = 0; i < n; i++) {
   cin >> a[i];
  }
  int ans = 0;
  for (int i = 0; i < n - 1; i++) {
   int idx = i, ele = a[i];
   for (int j = i + 1; j < n; j++) {
    if (a[j]  < ele) {
     ele = a[j];
     idx = j;
    }
   }
   ans += (idx - i + 1);
   int ii = i;
   while (idx > ii) {
    swap (a[idx], a[ii]);
    idx--;
    ii++;
   }
  }
  cout << "Case #" << tt << ": " << ans << '\n';
 }
 return 0;
}
