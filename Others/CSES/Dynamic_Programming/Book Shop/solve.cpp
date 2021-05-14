#include <bits/stdc++.h>
using namespace std;

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int n, x;
 cin >> n >> x;
 vector<int> h(n), s(n);
 for(auto& i: h) cin >> i;
 for(auto& i: s) cin >> i;
 vector<int> dp(x+1, 0);
 for(int i = 0; i < n; i++) {
  for(int j = x - h[i]; j >= 0; j--) {
   if(j == 0 || dp[j] > 0) dp[j + h[i]] = max(dp[j + h[i]], dp[j] + s[i]);
  }
 }
 cout << *max_element(dp.begin(), dp.end()) << '\n';
 return 0;
}
