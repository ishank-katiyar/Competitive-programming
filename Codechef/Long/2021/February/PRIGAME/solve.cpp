#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);

 const int maxn = static_cast <int> (1e6 + 1);
 vector<bool> is (maxn, true);

 for (int i = 2; i < maxn; i++) {
  if (is[i]) {
   for (int j = 2 * i; j < maxn; j += i) {
    is[j] = false;
   }
  }
 }

 vector<int> dp (maxn);

 for (int i = 2; i < maxn; i++) {
  dp[i] += dp[i - 1] + is[i];
 }

 int t;
 cin >> t;

 while (t--) {
  int x, y;
  cin >> x >> y;
  cout << (dp[x] <= y ? "Chef" : "Divyam") << '\n';
 }

 return 0;
}
