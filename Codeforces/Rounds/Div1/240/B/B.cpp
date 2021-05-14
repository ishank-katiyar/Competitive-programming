#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL
	#include "personal/debugger.hpp"
#else
	#define debug(a...)
#endif

const int mod = 1e9 + 7;

int main()
{
	int n , k;
	scanf("%d %d" , &n , &k);
	vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));	
	for(int i = 1; i <= n; i++) dp[i][1] = 1;
	for(int l = 2; l <= k; l++) {
		for(int i = 1; i <= n; i++) {
			for(int j = i; j <= n; j += i) {
				dp[j][l] += dp[i][l-1];	
				dp[j][l] %= mod;
			}
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) (ans += dp[i][k]) %= mod;
	printf("%d" , ans);
	return 0;
}