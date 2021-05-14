#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int64_t n;
 cin >> n;
 vector<int64_t> a (n);
 for (int i = 0; i < n; i++) {
  cin >> a[i];
 }
 int64_t sum = 0;
 int64_t ans = 0;
 map <int64_t, int64_t> mp;
 mp[0] = -1;
 int64_t latest = -1;
 for (int i = 0; i < n; i++) {
  sum += a[i];
  if (mp.count (sum)) {
   int64_t first = mp[sum];
   first += 1;
   int64_t dif = max ((int64_t) 0, first - latest);
   int64_t second = n - i;
   ans += dif * second;
   latest = max (latest, first);
  }
  mp[sum] = i;
 }
 cout << ((n * (n + 1)) / 2) - ans << '\n';
 return 0;
}
