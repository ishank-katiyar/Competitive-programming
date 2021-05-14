#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int n;
 cin >> n;
 int k;
 cin >> k;
 vector<vector<int>> A;
 bool ok = true;
 int SZ = -1;
 for (int i = 0; i < k; i++) {
  int sz;
  cin >> sz;
  vector<int> a(sz);
  for (auto& j: a) cin >> j;
  A.push_back(a);
  if (a[0] == 1) {
   SZ = sz;
   for (int j = 0; j < sz; j++) {
    if (a[j] != j + 1) {
     SZ = j;
     break;
    }
   }
  }
 }
 int ans;
 if (ok == true) ans = n - SZ - (k - 1) + n - SZ;
 else ans = n - k + n - 1;
 cout << ans << '\n';
 return 0;
}
