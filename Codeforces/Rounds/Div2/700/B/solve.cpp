#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int64_t A, B;
  cin >> A >> B;
  int n;
  cin >> n;
  vector<int64_t> a (n);
  for (int i = 0; i < n; i++) {
   cin >> a[i];
  }
  vector<int64_t> b (n);
  for (int i = 0; i < n; i++) {
   cin >> b[i];
  }
  int64_t sum = 0;
  for (int i = 0; i < n; i++) {
   int64_t cnt = (b[i] / A) + (b[i] % A != 0);
   sum += cnt * a[i];
  }
  bool ok = false;
  for (int i = 0; i < n; i++) {
   int64_t cnt = (b[i] / A) + (b[i] % A != 0);
   int64_t newB = sum - cnt * a[i];
   newB = B - newB;
   if (newB > (cnt - 1) * a[i]) {
    ok = true;
    break;
   }
  }
  cout << (ok ? "YES" : "NO") << '\n';
 }
 return 0;
}
