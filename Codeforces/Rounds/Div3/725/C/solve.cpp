#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, l , r;
		cin >> n >> l >> r;
		vector<int64_t> a (n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort (a.begin(), a.end());
		int64_t ans = 0;
		for (int i = 0; i < n; i++) {
			int idx1 = lower_bound (a.begin(), a.end(), l - a[i]) - a.begin();
			idx1 = max (idx1, i + 1);
			int idx2 = upper_bound (a.begin(), a.end(), r - a[i]) - a.begin() - max (idx1, i + 1);
			ans += max (idx2, 0);
		}
		cout << ans << '\n';
	}
	return 0;
}
