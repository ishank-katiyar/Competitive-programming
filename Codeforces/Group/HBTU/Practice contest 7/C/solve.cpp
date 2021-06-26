#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include "personal/debugger.hpp"
#else
	#define debug(a...) //
#endif

const int maxn = 1001;
vector<int> dp(maxn , 0);

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n;
	cin >> n;	
	int prev = -1;
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if(x == 1) {
			if(prev == -1) {
				prev = i;
				dp[i] = 1;
			}
			else {
				dp[i] = min(dp[prev] + 2 , dp[prev] + i - prev);
				prev = i;
			}
		}
	}
	debug(dp);
	cout << *max_element(dp.begin() , dp.end());
	return 0;
}

