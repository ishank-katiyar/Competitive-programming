#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 const int maxn = 2e6 + 1;
 vector<int> ans (maxn, 0);
 int sum = 1;
 int x = 1;
 while (sum <= maxn) {
  ans[sum] = x;
  x++;
  sum += x;
 }
 int a = 0;
 for (int i = maxn - 1; i >= 0; i--) {
  if (ans[i] != 0) a = ans[i];
  else ans[i] = a;
 }
 sum = 1;
 x = 1;
 while (sum <= maxn) {
  ans[sum - 1] = x + 1;
  x++;
  sum += x;
 }
 int t;
 cin >> t;
 while (t--) {
  int X;
  cin >> X;
  cout << ans[X] << '\n';
 }
 return 0;
}
