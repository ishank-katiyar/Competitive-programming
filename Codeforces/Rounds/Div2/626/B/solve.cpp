#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int n, m;
 cin >> n >> m;
 long long int K;
 cin >> K;
 vector<int> a(n);
 for (auto& i: a) cin >> i;
 vector<int> A;
 int cur = 0;
 for (int i = 0; i < n; i++) {
  if (a[i] == 0) {
   if (cur > 0) A.push_back(cur);
   cur = 0;
  }
  else cur++;
 }
 if (cur > 0) A.push_back(cur);
 vector<int> b(m);
 for (auto& i: b) cin >> i;
 vector<int> B;
 cur = 0;
 for (int i = 0; i < m; i++) {
  if (b[i] == 0) {
   if (cur > 0) B.push_back(cur);
   cur = 0;
  }
  else cur++;
 }
 if (cur > 0) B.push_back(cur);

 sort (A.begin(), A.end());
 sort (B.begin(), B.end());
 int sz_a = (int) A.size();
 int sz_b = (int) B.size();

 if (sz_a == 0 || sz_b == 0) {
  cout << 0 << '\n';
  return 0;
 }
 vector<long long int> dp_A(sz_a);
 dp_A[sz_a - 1] = A[sz_a - 1];
 for (int i = sz_a - 2; i >= 0; i--) {
  dp_A[i] += dp_A[i + 1] + A[i];
 }
 vector<long long int> dp_B(sz_b);
 dp_B[sz_b - 1] = B[sz_b - 1];
 for (int i = sz_b - 2; i >= 0; i--) {
  dp_B[i] += dp_B[i + 1] + B[i];
 }

 auto get_a = [&] (long long int X) -> long long int {
  int idx = lower_bound(A.begin(), A.end(), X) - A.begin();
  if (idx == sz_a) return 0;
  long long int ret = dp_A[idx] - (sz_a - idx) * (X - 1);
  return ret;
 };
 auto get_b = [&] (long long int X) -> long long int {
  int idx = lower_bound(B.begin(), B.end(), X) - B.begin();
  if (idx == sz_b) return 0;
  long long int ret = dp_B[idx] - (sz_b - idx) * (X - 1);
  return ret;
 };

 long long ans = 0;
 for (long long int i = 1; i * i <= K; i++) {
  if (K % i) continue;
  ans += get_a(i) * get_b(K / i);
  if (i != K / i) ans += get_a(K / i) * get_b(i);
 } 
 cout << ans << '\n';
 return 0;
}
