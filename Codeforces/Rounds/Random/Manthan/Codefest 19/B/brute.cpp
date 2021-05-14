#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int n;
 cin >> n;
 vector<int> a(n);
 for (auto& i: a) cin >> i;
 int ans = 1e9;
 for (int i = 0; i < n; i++) {
  for (int j = n; j > i; j--) {
   set <int> s;
   bool ok = true;
   for (int k = 0; k <= i; k++) {
    if (s.count(a[k]) > 0) {
     ok = false;
     break;
    }
    else s.insert (a[k]);
   }
   for (int k = j; k < n; k++) {
    if (s.count(a[k]) > 0) {
     ok = false;
     break;
    }
    else s.insert (a[k]);
   }
   if (ok) ans = min(ans, (j - 1) - (i + 1) + 1); 
  }
 }
 if (ans == 1e9) ans = 0;
 cout << ans << '\n';
 return 0;
}
