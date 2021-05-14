#include <bits/stdc++.h>
using namespace std;

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int n, k;
 cin >> n >> k;
 string s;
 cin >> s;
 vector<int> dp1(n, 1e9), dp2(n, 1e9);
 int ans = 1;
 dp1[0] = s[0] != 'a';
 dp2[0] = s[0] != 'b';
 for(int i = 1; i < n; i++) {
  dp1[i] = dp1[i - 1] + (s[i] != 'a');
  dp2[i] = dp2[i - 1] + (s[i] != 'b');
  int j = lower_bound(dp1.begin(), dp1.end(), dp1[i] - k) - dp1.begin();
  int k1 = lower_bound(dp2.begin(), dp2.end(), dp2[i] - k) - dp2.begin();
  j++, k1++;
  if(dp1[i] <= k) j = 0;
  if(dp2[i] <= k) k1 = 0;
  j = min(j, k1);
  ans = max(ans, i - j + 1);
 }
 cout << ans << '\n';
 return 0;
}
