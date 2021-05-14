#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include "personal/debugger.hpp"
#else
	#define debug(a...) //
#endif

const int maxn = 1000;
vector<vector<int>> arr(maxn , vector<int>(maxn , 0));

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n;
	cin >> n;
	arr[0][0] = 1;
	for(int i = 0; i <= n; i++) {
		arr[i][i + 1] = 1;
		arr[i + 1][i] = 1;
		arr[i + 1][i + 1] = 1;
	}	
	int ans = 0;
	for(auto& i : arr) for(auto&j : i) if(j == 1) ans++;
	cout << ans << '\n';
	for(int i = 0; i < maxn; i++) {
		for(int j = 0; j < maxn; j++) {
			if(arr[i][j] == 1) {
				cout << i << ' ' << j << '\n';
			}
		}
	}
	return 0;
}

