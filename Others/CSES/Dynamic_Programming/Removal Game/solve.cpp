#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int n;
 cin >> n;
 vector<ll> a(n);
 ll sum = 0;
 for(auto& i: a) cin >> i, sum += i;
 vector<vector<ll>> dp(n, vector<ll>(n));
 for(int i = 0; i < n; i++) dp[i][i] = a[i];
 for(int i = n-1; i >= 0; i--) {
  for(int j = i+1; j < n; j++) {
   dp[i][j] = max(a[i] - dp[i+1][j], a[j] - dp[i][j-1]);
  }
 }
 cout << (sum + dp[0][n-1]) / 2 << '\n';
 return 0;
}
