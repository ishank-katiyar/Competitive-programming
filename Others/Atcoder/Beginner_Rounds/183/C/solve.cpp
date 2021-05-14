#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int n, k;
 cin >> n >> k;
 vector<vector<long long>> a (n, vector<long long> (n));
 for (auto& i: a) for (auto& j: i) cin >> j;
 vector<int> A;
 for (int i = 2; i <= n; i++) {
  A.push_back (i);
 }
 long long cnt = 0;
 auto f = [&] (vector<int> aa) -> long long {
  int sz = (int) aa.size();
  long long ans = 0;
  for (int i = 0; i < sz; i++) {
   if (i == 0) {
    ans += a[0][aa[i] - 1];
   }
   else {
    ans += a[aa[i] - 1][aa[i - 1] - 1];
   }
  }
  ans += a[aa.back() - 1][0];
  return ans;
 };
 long long ans = f (A);
 if (ans == k) cnt++;
 while (next_permutation (A.begin(), A.end())) {
  ans = f (A);
  if (ans == k) cnt++;
 }
 cout << cnt << '\n';
 return 0;
}
