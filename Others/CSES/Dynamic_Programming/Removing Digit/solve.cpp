#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 1;

vector<int> dp(maxn, 1e9);

vector<int> f(int n) {
 vector<int> ret;
 while(n) {
  ret.push_back(n % 10);
  n /= 10;
 }
 return ret;
}

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 dp[0] = 0;
 for(int i = 1; i < maxn; i++) {
  vector<int> cur = f(i);
  for(auto& j: cur) dp[i] = min(dp[i], dp[i - j] + 1);
 }
 int n;
 cin >> n;
 cout << dp[n] << '\n';
 return 0;
}
