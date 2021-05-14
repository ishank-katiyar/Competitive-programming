#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL
	#include "personal/debugger.hpp"
#else 
	#define debug(a...)
#endif

const int maxn = 2e5 + 1;
vector<int> dp(maxn , 0);
vector<int> d(maxn , 0);

int main()
{
	int n;
	scanf("%d" , &n);
	if(n == 1) {
		puts("1");
		return 0;
	}
	vector<int> a(n);
	for(int i = 0; i < n; i++) scanf("%d" , &a[i]);
	for(int i = 0; i < n; i++) {
		for(int j = 2; j <= sqrt(a[i]); j++) {
			if(a[i] % j == 0) {
				dp[a[i]] = max(dp[a[i]] , d[j] + 1);
				dp[a[i]] = max(dp[a[i]] , d[a[i] / j] + 1);
			}
		}
		if(a[i] != 1) dp[a[i]] = max(dp[a[i]] , d[a[i]] + 1);
		for(int j = 2; j <= sqrt(a[i]); j++) {
			if(a[i] % j == 0) {
				d[j] = max(dp[a[i]] , d[j]);
				d[a[i] / j] = max(dp[a[i]] , d[a[i] /j]);
			}
		} 
		if(a[i] != 1) d[a[i]] = max(dp[a[i]] , d[a[i]]);
		//for(int k = 2; k <= 10; k++) debug(k,d[k]);
	}
	int mx = 0;
	for(int i = 0 ; i < n; i++) mx = max(dp[a[i]] , mx);
	printf("%d" , mx);
	return 0;
}