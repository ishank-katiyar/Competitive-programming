#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	if (k == 0) {
		cout << -1;
		return 0;
	}
	vector<int> ans (n + 1);
	for (int i = 1; i <= n; i++) ans[i] = i;
	ans[1] = k;
	for (int i = 2; i <= k; i++) {
		ans[i] = i - 1;
	}
	int aa = 0;
	for (int i = 1; i <= n; i++) {
		cout << ans[i];
		aa += (__gcd(ans[i], i) == 1);
		if (i < n) cout << ' ';
	}
	assert (aa == k);
	return 0;
}
