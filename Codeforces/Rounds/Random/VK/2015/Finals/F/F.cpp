#include "bits/stdc++.h"
using namespace std;

const int maxn = 1e6 + 1;
vector<int> dp(maxn);

int  main()
{
	int n;
	scanf("%d" , &n);
	if(n == 1) {
		puts("1");
		return 0;
	}
	vector<int> a(n);
	for(int i = 0; i < n;  i++) scanf("%d" , &a[i]);
	for(int i = 0; i < n; i++) {
		dp[a[i]]++;
		for(int j = 2 * a[i]; j < maxn; j += a[i]) {
			dp[j] = max(dp[j] , dp[a[i]]);
		}
	}
	int mx = (int) *max_element(dp.begin() , dp.end());
	printf("%d" , mx);
	return 0;
}