#include <bits/stdc++.h>
using namespace std;

#define int long long

const int maxn = 110000;
vector<int> c(maxn);

signed main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int n;
 cin >> n;
 int x;
 while(n--) cin >> x, c[x]++;
 vector<int> dp(maxn, 0);
 dp[1] = c[1];
 dp[2] = max(c[1], c[2] * 2);
 for(int i = 2; i < maxn; i++) dp[i] = max(dp[i-1], dp[i-2] + c[i] * i);
 cout << dp[maxn-1] << '\n';
 return 0;
}
