#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int64_t n, k;
 cin >> n >> k;
 assert (n <= 20);
 vector<tuple<int64_t, int64_t, int64_t>> a (n);
 for (int i = 0; i < n; i++) {
  cin >> get<0> (a[i]) >> get<1> (a[i]) >> get <2> (a[i]);
 }
 int64_t ans = 0;
 for (int mask = 1; mask < (1 << n); mask++) {
  int64_t minl = INT_MAX, maxr = INT_MIN, sum_value = 0;
  for (auto i = 0; i < n; i++) {
   if ((mask >> i) & 1) {
    minl = min (minl, get<0> (a[i]));
    maxr = max (maxr, get<1> (a[i]));
    sum_value += get<2> (a[i]);
   }
  }
  sum_value -= k * (maxr - minl);
  ans = max (ans, sum_value);
 }
 cout << ans << '\n';
 return 0;
}
