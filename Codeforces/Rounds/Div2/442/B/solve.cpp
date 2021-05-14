#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 string s;
 cin >> s;
 int n = (int) s.size();
 vector<int> a(n);
 vector<int> b(n);
 a[0] = s[0] == 'a';
 b[0] = s[0] == 'b';
 for (int i = 1; i < n; i++) {
  a[i] += a[i - 1] + (s[i] == 'a');
  b[i] += b[i - 1] + (s[i] == 'b');
 }
 auto get_a = [&] (int L, int R) -> int {
  if (L > R) return 0;
  int ret = 0;
  if (L == 0) ret = a[R];
  else ret = a[R] - a[L - 1];
  assert (ret >= 0);
  return ret;
 };
 auto get_b = [&] (int L, int R) -> int {
  if (L > R) return 0;
  int ret = 0;
  if (L == 0) ret = b[R];
  else ret = b[R] - b[L - 1];
  assert (ret >= 0);
  return ret;
 };
 int ans = 1e9;
 for (int i = 0; i < n; i++) {
  for (int j = i; j < n; j++) {
   int cur  = 0;
   cur += get_b(0, i - 1);
   cur += get_a(i, j - 1);
   cur += get_b(j + 1, n - 1);
   ans = min (ans, cur);
  } 
 }
 cout << n - ans << '\n';
 return 0;
}
