#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<int> a (n), b (m);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < m; i++) {
			cin >> b[i];
		}
		sort (a.begin(), a.end());
		sort (b.begin(), b.end());
		auto ff = [&] (const int l, const int r) -> int {
			// assert (l <= r);
			if (l > r) return 0;
			auto it = lower_bound(a.begin(), a.end(), l);
			auto it1 = upper_bound (a.begin(), a.end(), r);
			return it1 - it;
		};
		int ans = 0;
		ans = max (ans, ff (0, b.front() - 1));
		ans = max (ans, ff (b.back() + 1, 1e9 + 1));
		for (int i = 1; i < m; i++) {
			// int c = (b[i] + b[i - 1]) / 2;
			// int mn = min (c - b[i - 1] - 1, b[i] - c - 1);
			// if (mn >= 0) ans = max (ans, ff (c - mn, c + mn));
			// c += 1;
			// mn = min (c - b[i - 1] - 1, b[i] - c - 1);
			// if (mn >= 0) ans = max (ans, ff (c - mn, c + mn));
			ans = max (ans, ff (b[i - 1] + 1, b[i] - 1));
		}
		if (ans == 0) cout << "Impossible" << '\n';
		else cout << ans << '\n';
	}
	return 0;
}
