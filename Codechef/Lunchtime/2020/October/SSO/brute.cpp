#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int n;
  cin >> n;
  vector<long long> a (n);
  for (auto& i: a) cin >> i;
  long long ans = 0;
  for (int mask = 0; mask < (1LL << n); mask++) {
   long long sum = 0;
   for (int i = 0; i < n; i++) {
    if ((mask >> i) & 1) {
     sum += a[i];
    }
   }
   ans |= sum;
  }
  cout << ans << '\n';
 }
 return 0;
}
