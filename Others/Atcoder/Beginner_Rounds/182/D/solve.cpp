#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int n;
 cin >> n;
 vector<long long> a (n);
 vector<long long> pre_max (n);
 long long sum = 0;
 for (int i = 0; i < n; i++) {
  cin >> a[i];
  sum += a[i];
  if (i == 0) {
   pre_max[i] = a[i];
  }
  else {
   pre_max[i] = max (pre_max[i - 1], sum);
  }
 }
 long long ans = max (0LL, a[0]);
 sum = 0;
 long long S = 0;
 for (int i = 0; i < n - 1; i++) {
  sum += a[i];
  S += sum;
  ans = max (ans, S + pre_max [i + 1]);
 }
 sum += a[n - 1];
 S += sum;
 ans = max (ans, S);
 cout << ans << '\n';
 return 0;
}
/*
 * a1 a1 a2 a1 a2 a3
 */
