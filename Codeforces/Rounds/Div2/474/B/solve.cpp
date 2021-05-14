#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int n, k1, k2;
 cin >> n >> k1 >> k2;
 vector<int> a(n);
 for (auto& i: a) cin >> i;
 vector<int> b(n);
 for (auto& i: b) cin >> i;
 multiset<long long int> diff;
 for (int i = 0; i < n; i++) diff.insert(abs(a[i] - b[i]));
 int k = k1 + k2;
 while (k > 0) {
  int x = *(--diff.end());
  diff.erase(--diff.end());
  if (x > 0) {
   k--;
   x--;
   diff.insert(x);
   continue;
  }
  if (x == 0) {
   diff.insert(k % 2);
   break;
  }
 } 
 long long int ans = 0;
 for (auto i: diff) ans += i * i;
 cout << ans << '\n';
 return 0;
}
